#include"Player.h"

#include"../../../ActorContains/Body/OrientedBoundingBox.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../PlayerState/PlayerStateName.h"

//コンストラクタ
Player::Player(const IWorldPtr& world, const GSvector2& position, const IGameManagerPtr& gameManager)
	:Actor(
		world,
		ActorName::Player,
		position,
		gameManager,
		std::make_shared<NullTexture>(),
		std::make_shared<OrientedBoundingBox>(GSvector2{ 0.0f, 0.0f }, GSvector2{ 1.0f, 1.0f }, GS_MATRIX4_IDENTITY))
	, mStateManager(new PlayerStateManager(m_Position, m_Matrix, gameManager))
	, angle(0.0f)
{
	p_Renderer = gameManager->GetRenderer2D();
	mStateManager->change(*this, PlayerStateName::Idol);
}
//デストラクタ
Player::~Player() {
	delete mStateManager;
}
//更新処理
void Player::onUpdate(float deltaTime)
{
	//状態管理の更新処理
	mStateManager->action(*this, deltaTime);
	//行動制限
	m_Position = m_Position.clamp(GSvector2(0.0f, 0.0f), GSvector2(960, 704));

	//m_Matrix.setRotationZ(angle);

}
//描画処理
void Player::onDraw()const
{
	//Actor::onDraw();
	m_Body->transform(getPose())->draw();
	p_Renderer->DrawTexture("Player", m_Position);
}
//衝突判定
void Player::onCollide(Actor& other)
{
	//状態ごとの衝突判定
	mStateManager->collide(*this, other);
}

