#include "EnemyBase.h"
#include "../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../../../WorldContains/World/World.h"
#include "../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../CommandContains/CommandManagers/Interface/IECommandMgr.h"
#include "../../../PlayerWatch/PlayerWatch.h"
#include "../../../../../DrawManager/DisplayMode.h"

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
	const Body::MotionType motionType,
	const Body::BodyDataName dataName)
	: Actor(world, name, position, gameManager, texture, motionType, dataName)
	, m_MapType(type)
	, m_HitPoint(HitPoint(maxHp))
	, p_PlayerWatch(PlayerWatchUPtr())
	, p_StateManager(EnemyStateManagerUPtr())
	, p_CommandManager(IECommandMgrUPtr())
	, m_FourDirection(front){
	SetDirection(m_FourDirection);
	p_Texture->ChangeDisplayMode(DisplayMode::NonDisplay);
}

//�f�X�g���N�^
EnemyBase::~EnemyBase() {
	p_StateManager.reset();
	p_CommandManager.reset();
	p_PlayerWatch.reset();
}

//������
void EnemyBase::onInitialize() {
	//�\�����[�h
	p_Texture->ChangeDisplayMode(DisplayMode::Display);
	//�v���C���[�Ď�
	p_PlayerWatch.reset(new PlayerWatch(shared_from_this()));
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

//�Փ˂���
void EnemyBase::onCollide(Actor& other, const Body::ContactSet& contactSet) {
	//�X�s����Ԃ̃m�R�m�R�ƏՓ˂����ꍇ
	if (other.getName() == ActorName::Enemy_07) {
		if (dynamic_cast<EnemyBase*>(&other)->GetStateManager()->GetCurStateName() == EnemyStateName::Spin) {
			p_StateManager->change(EnemyStateName::Damage);
		}
	}

	//��Ԃ��Ƃ̏Փ˔���
	p_StateManager->collide(*this, other, contactSet);
}

//�X�e�[�g�}�l�[�W���[���擾����
EnemyStateManager* EnemyBase::GetStateManager() {
	return p_StateManager.get();
}

//�R�}���h�}�l�[�W���[���擾����
IECommandMgr* EnemyBase::GetCommandManager() {
	return p_CommandManager.get();
}

//�q�b�g�|�C���g���擾����
HitPoint & EnemyBase::GetHitPoint() {
	return m_HitPoint;
}

//�|���邩�|���Ȃ���
bool EnemyBase::CanDead() const {
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
	p_Texture->ChangeDisplayMode(DisplayMode::NonDisplay);
	p_Texture = m_TextureMap[textureName];
	p_Texture->Initialize();
	p_Texture->ChangeDisplayMode(DisplayMode::Display);
}

//���b�Z�[�W����
void EnemyBase::onMessage(EventMessage message, void* param) {
	//���b�Z�[�W����
	p_CommandManager->handleMessage(message, param);
	p_StateManager->handleMessage(message, param);
}