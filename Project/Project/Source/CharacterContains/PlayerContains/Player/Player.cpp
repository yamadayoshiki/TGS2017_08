#include"Player.h"

#include"../../../ActorContains/Body/OrientedBoundingBox.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../PlayerState/PlayerStateName.h"
#include"../../../ActorContains/ActorGroup.h"
#include"../Arm/Arm.h"
#include"../../../Utility/FourDirection/FourDirection.h"
#include "../../../Define/Def_Nakayama.h"
#include"../../../Utility/Animation/Animation.h"
#include"../../../Utility/Sound_Name.h"
#include"../../NeutralContains/Charge/Charge.h"

#include <algorithm>

//コンストラクタ
Player::Player(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager)
	:Actor(
		world,
		ActorName::Player,
		position,
		gameManager,
		std::make_shared<NullTexture>(),
		std::make_shared<OrientedBoundingBox>(GSvector2{ 0, 0 }, -90.0f, GSvector2{ 2.0f, 2.0f }))
	, p_Map(p_World->GetMap())
	, m_Parameter(gameManager->GetPlayerParameter())
{
	p_Renderer = gameManager->GetRenderer2D();
}

//デストラクタ
Player::~Player() {
	delete mStateManager;
	delete p_AnimationTexture;
	//delete m_Animation;
	p_Map.reset();
}

//初期化
void Player::initialize()
{
	//フレームカウンターの初期化
	m_Parameter.m_FrameCounter = 0;
	//チャージカウンターの初期化
	m_Parameter.m_ChargeConter = 0;
	//スタート地点の補間
	m_Parameter.m_StratPosition = m_Transform.m_Position;
	//コンボの初期化
	m_Parameter.m_Combo = 0;

	//名前の設定
	m_Name = "Player_Close";

	//アニメーションのパラメータの設定
	m_Animation = new Animation(*p_Renderer->GetTextureRect(m_Name), 64, 1);
	p_AnimationTexture = new AnimationTexture(m_Name, p_Renderer, m_Animation);
	p_AnimationTexture->Initialize();

	//ステートマネージャ生成、初期化
	mStateManager = new PlayerStateManager(shared_from_this(), p_GameManager);
	mStateManager->change(PlayerStateName::Idle);

	//アーム生成
	auto arm = std::make_shared<Arm>(p_World, m_Transform.m_Position, p_GameManager);
	arm->setPosition(m_Transform.m_Position + p_Body->forward() * 16);
	addChild(arm);
	mStateManager->addChild(ActorName::Player_Arm, arm);
}
//更新処理
void Player::onUpdate(float deltaTime)
{
	//アニメーションの更新
	p_AnimationTexture->Update(deltaTime);

	//状態管理の更新処理
	mStateManager->action(deltaTime);

	//一定フレーム後にコンボを初期化する
	m_Parameter.comboReset(deltaTime);

	if (mStateManager->currentState(PlayerStateName::O_Idle)) {
		//p_World->addActor(ActorGroup::Effect, std::make_shared<Charge>(p_World, getPosition(), p_GameManager));
	}

	//行動制限
	m_Transform.m_Position = m_Transform.m_Position.clamp(GSvector2(32.0f, 32.0f), GSvector2(1248, 928));

	//フレームカウンター
	m_Parameter.m_FrameCounter += deltaTime;
}
//描画処理
void Player::onDraw()const
{
	//p_Body->transform(getTransform())->draw();

	p_AnimationTexture->GetParameter()->SetPosition(m_Transform.m_Position);
	p_AnimationTexture->GetParameter()->SetRotate(m_Transform.m_Angle - 90);
	p_AnimationTexture->GetParameter()->SetCenter({ 32.0f, 32.0f });
	p_AnimationTexture->GetParameter()->SetScale({ 1.0f , 1.0f });
	p_AnimationTexture->GetParameter()->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	//アニメーションの描画
	p_AnimationTexture->Draw();

	GSvector2 drawPos = getPosition() - getBody()->forward() * 16;
	gsTextPos(drawPos.x, drawPos.y);
	gsDrawText("a");
}
//衝突判定
void Player::onCollide(Actor& other)
{
	//状態ごとの衝突判定
	mStateManager->collide(*this, other);
}

//プレイヤーパラメーターの取得
Player_Parameter& Player::getParameter()
{
	return m_Parameter;
}

//テクスチャの名前の設定
void Player::setName_Animation(const std::string& name)
{
	delete m_Animation;
	m_Name = name;
	m_Animation = new Animation(*p_Renderer->GetTextureRect(name), 64, 1);
	p_AnimationTexture->setName_Animation(name, m_Animation);
	p_AnimationTexture->Initialize();
}

//アニメーションのループ回数を取得
unsigned int Player::GetLoopCount()
{
	return p_AnimationTexture->GetLoopCount();
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