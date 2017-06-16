#include "EnemyBase.h"
#include "../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../../../WorldContains/World/World.h"
#include "../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"
#include "../../../PlayerWatch/PlayerWatch.h"

//�R���X�g���N�^
EnemyBase::EnemyBase(
	IWorld* world,
	const ActorName& name,
	const GSvector2& position,
	const FourDirection front,
	const int maxHp,
	const MapType type,
	const IGameManagerPtr& gameManager,
	const ITexturePtr& texture,
	const IBodyPtr& body)
	: Actor(world, name, position, gameManager, texture, body)
	, m_HitPoint(maxHp)
	, m_FourDirection(front)
	, m_MapType(type) {
	SetDirection(m_FourDirection);
}

//�f�X�g���N�^
EnemyBase::~EnemyBase() {
	p_StateManager.reset();
	p_CommandManager.reset();
	p_PlayerWatch.reset();
}

//������
void EnemyBase::initialize() {
	//�v���C���[�Ď�
	p_PlayerWatch.reset(new PlayerWatch(shared_from_this()));
	//�e��ŗL�̃R�}���h�̐ݒ�
	SetUpCommand();
	//�e��ŗL��State�̐ݒ�
	SetUpState();
}

//�X�V
void EnemyBase::onUpdate(float deltaTime) {
	//�e�N�X�`���X�V
	if (p_Texture != nullptr)
		p_Texture->Update(deltaTime);

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
	return p_StateManager.get();
}

//�R�}���h�}�l�[�W���[���擾����
IEnemyCommandManager* EnemyBase::GetCommandManager() {
	return p_CommandManager.get();
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
const PlayerWatch* EnemyBase::GetPlayerWatch()const {
	return p_PlayerWatch.get();
}

//�������擾
FourDirection EnemyBase::GetDirection() const {
	return m_FourDirection;
}

//������ݒ�
void EnemyBase::SetDirection(FourDirection dir) {
	m_FourDirection = dir;
	setAngle(m_FourDirection.GetAngle());
}

//�ړ��}�b�v�^�C�v���擾
MapType EnemyBase::GetMapType() const {
	return m_MapType;
}

//�e�N�X�`���̐؂�ւ�
void EnemyBase::Settexture(const std::string textureName) {
	p_Texture->Finalize();
	p_Texture = m_TextureMap[textureName];
	p_Texture->Initialize();
}

//���b�Z�[�W����
void EnemyBase::onMessage(EventMessage message, void* param) {
	//���b�Z�[�W����
	p_CommandManager->handleMessage(message, param);
	p_StateManager->handleMessage(message, param);
}