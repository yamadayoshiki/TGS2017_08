#include"Player.h"

#include"../../../ActorContains/Body/OrientedBoundingBox.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../PlayerState/PlayerStateName.h"

//�R���X�g���N�^
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
	, child(new Arm(p_World, m_Position, m_Matrix, p_GameManager))
{
	p_Renderer = gameManager->GetRenderer2D();
	mStateManager->change(*this, PlayerStateName::Idol);
}
//�f�X�g���N�^
Player::~Player() {
	delete mStateManager;
	//delete child;
}
//�X�V����
void Player::onUpdate(float deltaTime)
{
	//��ԊǗ��̍X�V����
	mStateManager->action(*this, deltaTime);
	//�s������
	m_Position = m_Position.clamp(GSvector2(0.0f, 0.0f), GSvector2(960, 704));

	child->setMatrix(m_Matrix);
	child->setPosition(m_Position - GSvector2(m_Matrix.getAxisY()) * 16);

	//m_Matrix.setRotationZ(angle);
}
//�`�揈��
void Player::onDraw()const
{
	m_Body->transform(getPose())->draw();
	p_Renderer->DrawTexture("Player", m_Position);
	child->onDraw();
}
//�Փ˔���
void Player::onCollide(Actor& other)
{
	//��Ԃ��Ƃ̏Փ˔���
	mStateManager->collide(*this, other);
}

