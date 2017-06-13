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

//�R���X�g���N�^
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

//�f�X�g���N�^
Player::~Player() {
	delete mStateManager;
	delete p_AnimationTexture;
	//delete m_Animation;
	p_Map.reset();
}

//������
void Player::initialize()
{
	//�t���[���J�E���^�[�̏�����
	m_Parameter.m_FrameCounter = 0;
	//�`���[�W�J�E���^�[�̏�����
	m_Parameter.m_ChargeConter = 0;
	//�X�^�[�g�n�_�̕��
	m_Parameter.m_StratPosition = m_Transform.m_Position;
	//�R���{�̏�����
	m_Parameter.m_Combo = 0;

	//���O�̐ݒ�
	m_Name = "Player_Close";

	//�A�j���[�V�����̃p�����[�^�̐ݒ�
	m_Animation = new Animation(*p_Renderer->GetTextureRect(m_Name), 64, 1);
	p_AnimationTexture = new AnimationTexture(m_Name, p_Renderer, m_Animation);
	p_AnimationTexture->Initialize();

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
	//�A�j���[�V�����̍X�V
	p_AnimationTexture->Update(deltaTime);

	//��ԊǗ��̍X�V����
	mStateManager->action(deltaTime);

	//���t���[����ɃR���{������������
	m_Parameter.comboReset(deltaTime);

	if (mStateManager->currentState(PlayerStateName::O_Idle)) {
		//p_World->addActor(ActorGroup::Effect, std::make_shared<Charge>(p_World, getPosition(), p_GameManager));
	}

	//�s������
	m_Transform.m_Position = m_Transform.m_Position.clamp(GSvector2(32.0f, 32.0f), GSvector2(1248, 928));

	//�t���[���J�E���^�[
	m_Parameter.m_FrameCounter += deltaTime;
}
//�`�揈��
void Player::onDraw()const
{
	//p_Body->transform(getTransform())->draw();

	p_AnimationTexture->GetParameter()->SetPosition(m_Transform.m_Position);
	p_AnimationTexture->GetParameter()->SetRotate(m_Transform.m_Angle - 90);
	p_AnimationTexture->GetParameter()->SetCenter({ 32.0f, 32.0f });
	p_AnimationTexture->GetParameter()->SetScale({ 1.0f , 1.0f });
	p_AnimationTexture->GetParameter()->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	//�A�j���[�V�����̕`��
	p_AnimationTexture->Draw();

	GSvector2 drawPos = getPosition() - getBody()->forward() * 16;
	gsTextPos(drawPos.x, drawPos.y);
	gsDrawText("a");
}
//�Փ˔���
void Player::onCollide(Actor& other)
{
	//��Ԃ��Ƃ̏Փ˔���
	mStateManager->collide(*this, other);
}

//�v���C���[�p�����[�^�[�̎擾
Player_Parameter& Player::getParameter()
{
	return m_Parameter;
}

//�e�N�X�`���̖��O�̐ݒ�
void Player::setName_Animation(const std::string& name)
{
	delete m_Animation;
	m_Name = name;
	m_Animation = new Animation(*p_Renderer->GetTextureRect(name), 64, 1);
	p_AnimationTexture->setName_Animation(name, m_Animation);
	p_AnimationTexture->Initialize();
}

//�A�j���[�V�����̃��[�v�񐔂��擾
unsigned int Player::GetLoopCount()
{
	return p_AnimationTexture->GetLoopCount();
}

//csv�Ő���(�g�p���p�����override)
ActorPtr Player::CsvGenerate(const int x, const int y, const int csvparam) {
	GSvector2 position = p_World->GetMap()->CsvPosCnvVector2(x, y, MapType::Double);
	FourDirection dir = FourDirection((FourDirectionName)csvparam);
	return std::make_shared<Player>(p_World, position, p_GameManager);
}

//���b�Z�[�W����
void Player::onMessage(EventMessage message, void* param) {
	//���b�Z�[�W����
	mStateManager->handleMessage(message, param);
}