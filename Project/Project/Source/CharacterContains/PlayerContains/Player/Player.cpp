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

//�R���X�g���N�^
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

//�f�X�g���N�^
Player::~Player() {
	delete mStateManager;
	p_Map.reset();
}

//������
void Player::onInitialize()
{
	//�t���[���J�E���^�[�̏�����
	m_Parameter.m_FrameCounter = 0;
	//�`���[�W�J�E���^�[�̏�����
	m_Parameter.m_ChargeConter = 0;
	//�X�^�[�g�n�_�̕��
	m_Parameter.m_StratPosition = getPosition();
	//���W�̐ݒ�
	m_Parameter.setPosition(p_Transform->m_Position);
	//�R���{�̏�����
	m_Parameter.m_Combo = 0;

	//���O�̐ݒ�
	m_Name = "Player_Close";

	//�X�e�[�g�}�l�[�W�������A������
	mStateManager = new PlayerStateManager(shared_from_this(), p_GameManager);
	mStateManager->change(PlayerStateName::Idle);

	p_Texture->ChangeDisplayMode(DisplayMode::Display);

	//�A�[������
	auto arm = std::make_shared<Arm>(p_World, getPosition(), p_GameManager);
	arm->setPosition(getPosition() + getTransform()->GetForward() * 16);
	addChild(arm);
	mStateManager->addChild(ActorName::Player_Arm, arm);
}
//�X�V����
void Player::onUpdate(float deltaTime)
{
	//��ԊǗ��̍X�V����
	mStateManager->action(deltaTime);

	//�v���C���[�̍��W�̐ݒ�
	m_Parameter.setPosition(p_Transform->m_Position);

	//�s������
	p_Transform->m_Position = getPosition().clamp(GSvector2(32.0f, 32.0f), GSvector2(1248, 928));

	//�t���[���J�E���^�[
	m_Parameter.m_FrameCounter += deltaTime;

	int i = 0;
	i= mStateManager->currentState(i);
	if (i != 0)
		std::cout << std::to_string(i) << std::endl;;
}
//�`�揈��
void Player::onDraw()const {
}

//�Փ˔���
void Player::onCollide(Actor& other, const Body::ContactSet& contactSet) {
	if (other.getName() == ActorName::BreakWall)
		p_Transform->m_Position += contactSet.m_SumVec;

	//��Ԃ��Ƃ̏Փ˔���
	mStateManager->collide(*this, other, contactSet);
}

//�v���C���[�p�����[�^�[�̎擾
Player_Parameter& Player::getParameter() {
	return m_Parameter;
}

//�e�N�X�`���̖��O�̐ݒ�
void Player::setName_Animation(const std::string& name) {
	m_Name = name;
	p_Texture = std::make_shared<AnimationTexture>(m_Name, p_GameManager->GetDrawManager(), DrawOrder::Player, 64, 1);
	p_Texture->Initialize();
}

//�A�j���[�V�����̃��[�v�񐔂��擾
unsigned int Player::GetLoopCount() {
	return p_Texture->GetLoopCount();
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