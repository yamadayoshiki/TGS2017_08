#include"Player.h"

#include"../../../ActorContains/Body/OrientedBoundingBox.h"
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../PlayerState/PlayerStateName.h"
#include"../Arm/Arm.h"
#include"../../../Utility/FourDirection/FourDirection.h"
#include "../../../Define/Def_Nakayama.h"
#include"../../../Utility/Animation/Animation.h"

#include <algorithm>

//�R���X�g���N�^
Player::Player(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager)
	:Actor(
		world,
		ActorName::Player,
		position,
		gameManager,
		std::make_shared<NullTexture>(),
		std::make_shared<OrientedBoundingBox>(GSvector2{ 0, 0 }, -90.0f, GSvector2{ 2.0f, 2.0f })), angle(0.0f)
	, p_Map(p_World->GetMap())
	,m_Parameter(gameManager->GetPlayerParameter())
{
	p_Renderer = gameManager->GetRenderer2D();
}
//�f�X�g���N�^
Player::~Player() {
	delete mStateManager;
	delete p_Animation;
}

//������
void Player::initialize()
{
	//���O�̐ݒ�
	setName("Player_Close");
	//�X�^�[�g�n�_�̕��
	m_Parameter.m_StratPosition = m_Transform.m_Position;

	//Animation	

	//�v���C���[�p�����[�^�[�̐ݒ�
	//m_Parameter = p_GameManager->GetPlayerParameter();

	//�X�e�[�g�}�l�[�W�������A������
	mStateManager = new PlayerStateManager(shared_from_this(), p_GameManager);
	mStateManager->change(PlayerStateName::Idle);

	//�A�[������
	auto arm = std::make_shared<Arm>(p_World, m_Transform.m_Position, p_GameManager);
	arm->setPosition(m_Transform.m_Position + p_Body->forward() * 16);
	addChild(arm);
	mStateManager->addChild(ActorName::Player_Arm, arm);
}
//�X�V����
void Player::onUpdate(float deltaTime)
{
	//��ԊǗ��̍X�V����
	mStateManager->action(deltaTime);

	//�s������
	m_Transform.m_Position = m_Transform.m_Position.clamp(GSvector2(32.0f, 32.0f), GSvector2(1248, 928));
}
//�`�揈��
void Player::onDraw()const
{
	//p_Body->transform(getTransform())->draw();

	Texture2DParameter param;
	param.SetPosition(m_Transform.m_Position);
	param.SetRotate(m_Transform.m_Angle - 90);
	param.SetCenter({ 32.0f, 32.0f });
	param.SetRect(*p_Renderer->GetTextureRect(m_Name));
	param.SetScale({ 1.0f , 1.0f });
	param.SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	p_Renderer->DrawTexture(m_Name, param);
	//child->onDraw();

	/*gsTextPos(m_Transform.m_Position.x, m_Transform.m_Position.y);
	gsDrawText("a");*/
}
//�Փ˔���
void Player::onCollide(Actor& other)
{
	//��Ԃ��Ƃ̏Փ˔���
	mStateManager->collide(*this, other);
	//dynamic_cast<Arm*>(child.get())->onCollide(other);
}

//�v���C���[�p�����[�^�[�̎擾
Player_Parameter& Player::getParameter()
{
	return m_Parameter;
}

//�e�N�X�`���̖��O�̐ݒ�
void Player::setName(const std::string& name)
{
	m_Name = name;
}

ActorPtr Player::clone(const GSvector2 & position, const FourDirection& front)
{
	m_Transform.m_Position = position;
	return shared_from_this();
}

//���b�Z�[�W����
void Player::onMessage(EventMessage message, void* param) {
	//���b�Z�[�W����
	mStateManager->handleMessage(message, param);
}