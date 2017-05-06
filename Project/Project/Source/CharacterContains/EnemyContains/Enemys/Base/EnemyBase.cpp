#include "EnemyBase.h"
#include "../../../../WorldContains/World/World.h"

//�R���X�g���N�^
EnemyBase::EnemyBase(
	const IWorldPtr& world,
	const ActorName& name,
	const GSvector2& position,
	const float speed,
	const IGameManagerPtr& gameManager,
	const ITexturePtr& texture,
	const IBodyPtr& body)
	: Actor(world, name, position, gameManager, texture, body)
	, m_Speed(speed)
	, p_StateManager(new EnemyStateManager(shared_from_this()))
	, p_CommandManager(new EnemyCommandManager(shared_from_this())) {
}

//�f�X�g���N�^
EnemyBase::~EnemyBase() {
	delete p_StateManager;
	delete p_CommandManager;
}

//������
void EnemyBase::initialize() {
	//�R�}���h�}�l�[�W���[�̏�����
	p_CommandManager->Initialize();
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
EnemyCommandManager* EnemyBase::GetCommandManager() {
	return p_CommandManager;
}