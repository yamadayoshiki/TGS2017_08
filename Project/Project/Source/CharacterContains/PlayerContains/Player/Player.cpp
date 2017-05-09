#include"Player.h"

#include"../../../ActorContains/Body/OrientedBoundingBox.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../PlayerState/PlayerStateName.h"
#include"../Arm/Arm.h"

//�R���X�g���N�^
Player::Player(const IWorldPtr& world, const GSvector2& position, const IGameManagerPtr& gameManager)
	:Actor(
		world,
		ActorName::Player,
		position,
		gameManager,
		std::make_shared<NullTexture>(),
		std::make_shared<OrientedBoundingBox>(GSvector2{ 32.0f, 32.0f }, 0.0f, GSvector2{ 2.0f, 2.0f })), angle(0.0f)
{
	p_Renderer = gameManager->GetRenderer2D();
}
//�f�X�g���N�^
Player::~Player() {
	delete mStateManager;
}
void Player::initialize()
{
	//�X�e�[�g�}�l�[�W�������A������
	//mStateManager = new PlayerStateManager(m_Position, m_Matrix, shared_from_this(), p_GameManager);
	mStateManager = new PlayerStateManager(m_Transform.m_Position, GSmatrix4(GS_MATRIX4_IDENTITY), shared_from_this(), p_GameManager);
	mStateManager->change(PlayerStateName::Idle);

	//�A�[������
	//auto arm = std::make_shared<Arm>(p_World, m_Position, m_Matrix, p_GameManager);
	auto arm = std::make_shared<Arm>(p_World, m_Transform.m_Position, GSmatrix4(GS_MATRIX4_IDENTITY), p_GameManager);
	//arm->setPosition(m_Position - GSvector2(m_Matrix.getAxisY()) * 16);
	arm->setPosition(m_Transform.m_Position - m_Transform.m_Forward * 16);
	addChild(arm);
	mStateManager->addChild(ActorName::Player_Arm, arm);
}
//�X�V����
void Player::onUpdate(float deltaTime)
{
	//��ԊǗ��̍X�V����
	mStateManager->action(deltaTime);
	//�s������
	//m_Position = m_Position.clamp(GSvector2(0.0f, 0.0f), GSvector2(960, 704));
	m_Transform.m_Position = m_Transform.m_Position.clamp(GSvector2(0.0f, 0.0f), GSvector2(960, 704));

	//child->setMatrix(m_Matrix);
	//child->setPosition(m_Position - GSvector2(m_Matrix.getAxisY()) * 16);
}
//�`�揈��
void Player::onDraw()const
{
	p_Body->transform(getTransform())->draw();
	//p_Renderer->DrawTexture("Player", m_Position);
	p_Renderer->DrawTexture("Player", m_Transform.m_Position);
	//child->onDraw();
}
//�Փ˔���
void Player::onCollide(Actor& other)
{
	//��Ԃ��Ƃ̏Փ˔���
	mStateManager->collide(*this, other);
	//dynamic_cast<Arm*>(child.get())->onCollide(other);
}

