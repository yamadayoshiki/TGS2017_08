#include "EnemyBase.h"
#include "../../../../WorldContains/World/World.h"
#include "../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"
#include "../../PlayerWatch/PlayerWatch.h"

//�R���X�g���N�^
EnemyBase::EnemyBase(
	IWorld* world,
	const ActorName& name,
	const GSvector2& position,
	const FourDirection front,
	const float speed,
	const int maxHp,
	const IGameManagerPtr& gameManager,
	const ITexturePtr& texture,
	const IBodyPtr& body)
	: Actor(world, name, position, gameManager, texture, body)
	, m_HitPoint(maxHp)
	, m_FourDirection(front) {
	SetDirection(front);
}

//�f�X�g���N�^
EnemyBase::~EnemyBase() {
	delete p_StateManager;
	delete p_PlayerWatch;
}

//������
void EnemyBase::initialize() {
	//�v���C���[�Ď�
	p_PlayerWatch = new PlayerWatch(getWorld()->GetMap(), shared_from_this());
	//�e��ŗL�̃R�}���h�̐ݒ�
	SetUpCommand();
	//�e��ŗL��State�̐ݒ�
	SetUpState();
}

//�X�V
void EnemyBase::onUpdate(float deltaTime) {
	//�R�}���h���̍X�V
	p_CommandManager->Update(deltaTime);

	//��ԊǗ��̍X�V
	p_StateManager->action(deltaTime);

	//�n�`�Ƃ̏Փ˔���

}

//�`��
void EnemyBase::onDraw() const {

}

//�Փ˂���
void EnemyBase::onCollide(Actor& other) {
	//��Ԃ��Ƃ̏Փ˔���
	p_StateManager->collide(*this, other);
}

//�X�e�[�g�}�l�[�W���[���擾����
EnemyStateManager* EnemyBase::GetStateManager() {
	return p_StateManager;
}

//�R�}���h�}�l�[�W���[���擾����
IEnemyCommandManagerPtr EnemyBase::GetCommandManager() {
	return p_CommandManager;
}

//�q�b�g�|�C���g���擾����
HitPoint & EnemyBase::GetHitPoint() {
	return m_HitPoint;
}

//�|���邩�|���Ȃ���
bool EnemyBase::CanDead() {
	return m_HitPoint.CanDead();
}

//�v���C���[�Ď��N���X���擾����
PlayerWatch* EnemyBase::GetPlayerWatch() {
	return p_PlayerWatch;
}

//�������擾
FourDirection EnemyBase::GetDirection() const {
	return m_FourDirection;
}

//������ݒ�
void EnemyBase::SetDirection(FourDirection dir) {
	m_FourDirection = dir;
	setAngle(m_FourDirection.GetTurn(
		TurnDirection(TurnDirectionName::Clockwise)).GetAngle());
}

//���b�Z�[�W����
void EnemyBase::onMessage(EventMessage message, void* param) {
	//���b�Z�[�W����
	p_CommandManager->handleMessage(message, param);
	p_StateManager->handleMessage(message, param);
}