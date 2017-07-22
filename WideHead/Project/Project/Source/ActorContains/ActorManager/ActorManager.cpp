#include "ActorManager.h" 
#include "../Actor/Actor.h"
#include "../ActorGroup.h"
#include "../NullActor/NullActor.h"
#include "../../CharacterContains/EnemyContains/EnemyManager/EnemyManager.h"
#include <memory>
#include <chrono>

// �R���X�g���N�^ 
ActorManager::ActorManager() {
	p_Root = std::make_unique<Actor>();
	initialize();
}

// �f�X�g���N�^
ActorManager::~ActorManager() {
	m_actors.clear();
	p_Root->clearChildren();
}

void ActorManager::SetUp(IWorld * world, const IGameManagerPtr & gameManager) {
	p_EnemyManager.lock()->SetUp(world, gameManager);
}

// ������ 
void ActorManager::initialize() {
	m_actors[ActorGroup::None] = std::make_shared<Actor>();
	m_actors[ActorGroup::UI] = std::make_shared<Actor>(ActorName::UI_ALL);
	m_actors[ActorGroup::Effect] = std::make_shared<Actor>();
	m_actors[ActorGroup::Player] = std::make_shared<Actor>(ActorName::PlayerManager);
	m_actors[ActorGroup::Enemy] = std::make_shared<EnemyManager>();
	p_EnemyManager = std::dynamic_pointer_cast<EnemyManager>(m_actors[ActorGroup::Enemy]);

	p_Root->clearChildren();

	p_Root->addChild(m_actors[ActorGroup::None]);
	p_Root->addChild(m_actors[ActorGroup::UI]);
	p_Root->addChild(m_actors[ActorGroup::Effect]);
	p_Root->addChild(m_actors[ActorGroup::Player]);
	p_Root->addChild(m_actors[ActorGroup::Enemy]);
}

// �X�V 
void ActorManager::update(float deltaTime) {
	p_Root->update(deltaTime);
	collide();
	p_Root->LateUpdate();
	p_Root->removeChildren_dead();
}

// �`�� 
void ActorManager::draw() const {
	p_Root->draw();
}

// �A�N�^�[�̒ǉ� 
void ActorManager::addActor(ActorGroup group, const ActorPtr& actor) {
	//������
	actor->initialize();
	//�ǉ�
	m_actors[group]->addChild(actor);
}

// �A�N�^�[�̌��� 
ActorPtr ActorManager::findActor(const ActorName& name) {
	return p_Root->findChildren_NullActor(name);
}

// ���b�Z�[�W���� 
void ActorManager::handleMessage(EventMessage message, void* param) {
	p_Root->handleMessage(message, param);
}

int ActorManager::getCount(ActorGroup group) const {
	return m_actors.at(group)->getCount();
}

int ActorManager::GetSurviverSum() {
	return p_EnemyManager.lock()->GetSurviverSum();
}

//�C�ӂ̏Փ˔���
void ActorManager::OptionalCollide(Actor* actor, ActorGroup actorGroup) {
	actor->collideChildren(*m_actors[actorGroup]);
}

// �Փ˔��� 
void ActorManager::collide() {
	m_actors[ActorGroup::Player]->collideChildren(*m_actors[ActorGroup::Enemy]);
	p_EnemyManager.lock()->EnemyCollide();
}