#include "EnemyBase.h"
#include "../../../../WorldContains/World/World.h"
#include "../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"

//�R���X�g���N�^
EnemyBase::EnemyBase(
	IWorld* world,
	const ActorName& name,
	const GSvector2& position,
	const float speed,
	const IGameManagerPtr& gameManager,
	const ITexturePtr& texture,
	const IBodyPtr& body)
	: Actor(world, name, position, gameManager, texture, body)
	, m_Speed(speed) {
}

//�f�X�g���N�^
EnemyBase::~EnemyBase() {
	delete p_StateManager;
}

//������
void EnemyBase::initialize() {
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

//���b�Z�[�W����
void EnemyBase::onMessage(EventMessage message, void* param) {
	//���b�Z�[�W����
	p_StateManager->handleMessage(message, param);
}