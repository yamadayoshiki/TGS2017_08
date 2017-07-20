#include"Player.h"
#include "../../../ActorContains/Transform/Transform.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../PlayerState/PlayerStateName.h"
#include"../../../ActorContains/ActorGroup.h"
#include"../Arm/Arm.h"
#include"../../../Utility/FourDirection/FourDirection.h"
#include "../../../Define/Def_Nakayama.h"
#include"../../../Utility/Animation/Animation.h"
#include"../../../Utility/Sound/SoundName.h"
#include"../../NeutralContains/Charge_Effect/Charge.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../../ActorContains/BodyContains/Elements/ContactSet/ContactSet.h"
#include <algorithm>

//コンストラクタ
Player::Player(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager)
	:Actor(
		world,
		ActorName::Player,
		position,
		gameManager,
		std::make_shared<AnimationTexture>("Player_Close", gameManager->GetDrawManager(), DrawOrder::Player, 64, 1),
		Body::MotionType::Player,
		Body::BodyDataName::Player_Close)
	, p_Map(p_World->GetMap())
	, m_Parameter(gameManager->GetPlayerParameter()) {
	p_Texture->GetParameter()->m_Center = { 32.0f, 32.0f };
	p_Texture->ChangeDisplayMode(DisplayMode::NonDisplay);
}

//デストラクタ
Player::~Player() {
	delete mStateManager;
	p_Map.reset();
}

//初期化
void Player::onInitialize()
{
	//フレームカウンターの初期化
	m_Parameter.m_FrameCounter = 0;
	//チャージカウンターの初期化
	m_Parameter.m_ChargeConter = 0;
	//スタート地点の補間
	m_Parameter.m_StratPosition = getPosition();
	//座標の設定
	m_Parameter.setPosition(p_Transform->m_Position);
	//コンボの初期化
	m_Parameter.m_Combo = 0;

	//名前の設定
	m_Name = "Player_Close";

	//ステートマネージャ生成、初期化
	mStateManager = new PlayerStateManager(shared_from_this(), p_GameManager);
	mStateManager->change(PlayerStateName::Idle);

	p_Texture->ChangeDisplayMode(DisplayMode::Display);

	//アーム生成
	auto arm = std::make_shared<Arm>(p_World, getPosition(), p_GameManager);
	arm->setPosition(getPosition() + getTransform()->GetForward() * 16);
	addChild(arm);
	mStateManager->addChild(ActorName::Player_Arm, arm);
}
//更新処理
void Player::onUpdate(float deltaTime)
{
	//状態管理の更新処理
	mStateManager->action(deltaTime);

	//プレイヤーの座標の設定
	m_Parameter.setPosition(p_Transform->m_Position);

	//行動制限
	p_Transform->m_Position = getPosition().clamp(GSvector2(32.0f, 32.0f), GSvector2(1248, 928));

	//フレームカウンター
	m_Parameter.m_FrameCounter += deltaTime;

	int i = 0;
	i= mStateManager->currentState(i);
	if (i != 0)
		std::cout << std::to_string(i) << std::endl;;
}
//描画処理
void Player::onDraw()const {
}

//衝突判定
void Player::onCollide(Actor& other, const Body::ContactSet& contactSet) {
	if (other.getName() == ActorName::BreakWall)
		p_Transform->m_Position += contactSet.m_SumVec;

	//状態ごとの衝突判定
	mStateManager->collide(*this, other, contactSet);
}

//プレイヤーパラメーターの取得
Player_Parameter& Player::getParameter() {
	return m_Parameter;
}

//テクスチャの名前の設定
void Player::setName_Animation(const std::string& name) {
	m_Name = name;
	p_Texture = std::make_shared<AnimationTexture>(m_Name, p_GameManager->GetDrawManager(), DrawOrder::Player, 64, 1);
	p_Texture->Initialize();
}

//アニメーションのループ回数を取得
unsigned int Player::GetLoopCount() {
	return p_Texture->GetLoopCount();
}

//csvで生成(使用時継承先でoverride)
ActorPtr Player::CsvGenerate(const int x, const int y, const int csvparam) {
	GSvector2 position = p_World->GetMap()->CsvPosCnvVector2(x, y, MapType::Double);
	FourDirection dir = FourDirection((FourDirectionName)csvparam);
	return std::make_shared<Player>(p_World, position, p_GameManager);
}

//メッセージ処理
void Player::onMessage(EventMessage message, void* param) {
	//メッセージ処理
	mStateManager->handleMessage(message, param);
}