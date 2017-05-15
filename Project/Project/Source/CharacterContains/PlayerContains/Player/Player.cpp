#include"Player.h"

#include"../../../ActorContains/Body/OrientedBoundingBox.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../PlayerState/PlayerStateName.h"
#include"../Arm/Arm.h"

//コンストラクタ
Player::Player(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager)
	:Actor(
		world,
		ActorName::Player,
		position,
		gameManager,
		std::make_shared<NullTexture>(),
		std::make_shared<OrientedBoundingBox>(GSvector2{ 0, 0 }, -90.0f, GSvector2{ 2.0f, 2.0f })), angle(0.0f)
{
	p_Renderer = gameManager->GetRenderer2D();
}
//デストラクタ
Player::~Player() {
	delete mStateManager;
}
void Player::initialize()
{
	//p_CharacterManager = p_World->getCharacterManager();
	//ステートマネージャ生成、初期化
	//mStateManager = new PlayerStateManager(m_Position, m_Matrix, shared_from_this(), p_GameManager);
	mStateManager = new PlayerStateManager(shared_from_this(), p_GameManager);
	mStateManager->change(PlayerStateName::Idle);


	//アーム生成
	//auto arm = std::make_shared<Arm>(p_World, m_Position, m_Matrix, p_GameManager);
	auto arm = std::make_shared<Arm>(p_World, m_Transform.m_Position, GSmatrix4(GS_MATRIX4_IDENTITY), p_GameManager);
	//arm->setPosition(m_Position - GSvector2(m_Matrix.getAxisY()) * 16);
	arm->setPosition(m_Transform.m_Position + p_Body->forward() * 16);
	addChild(arm);
	mStateManager->addChild(ActorName::Player_Arm, arm);
}
//更新処理
void Player::onUpdate(float deltaTime)
{
	//状態管理の更新処理
	mStateManager->action(deltaTime);
	//行動制限
	//m_Position = m_Position.clamp(GSvector2(0.0f, 0.0f), GSvector2(960, 704));
	m_Transform.m_Position = m_Transform.m_Position.clamp(GSvector2(0.0f, 0.0f), GSvector2(960, 704));

	if (mStateManager->currentState(PlayerStateName::Rounds) == true) {
	}

	
	//child->setMatrix(m_Matrix);
	//child->setPosition(m_Position - GSvector2(m_Matrix.getAxisY()) * 16);
}
//描画処理
void Player::onDraw()const
{
	p_Body->transform(getTransform())->draw();
	//p_Renderer->DrawTexture("Player", m_Position);

	Texture2DParameter param;
	param.SetPosition(m_Transform.m_Position);
	param.SetCenter({ 32.0f, 32.0f });
	param.SetRect(*p_Renderer->GetTextureRect("Player"));
	param.SetScale({ 1.0f , 1.0f });
	param.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	p_Renderer->DrawTexture("Player", param);
	//child->onDraw();

	gsTextPos(m_Transform.m_Position.x, m_Transform.m_Position.y);
	gsDrawText("a");
}
//衝突判定
void Player::onCollide(Actor& other)
{
	//状態ごとの衝突判定
	mStateManager->collide(*this, other);
	//dynamic_cast<Arm*>(child.get())->onCollide(other);
	if (mStateManager->currentState(PlayerStateName::Rounds) == true) {
		//p_CharacterManager->SetRoundActor(other);
	}
}

