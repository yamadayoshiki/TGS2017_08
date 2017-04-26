#include "ActorManager.h" 
#include "../ActorGroup.h"
#include <memory>

// �R���X�g���N�^ 
ActorManager::ActorManager() {
	initialize();
}

// ������ 
void ActorManager::initialize()
{
	m_actors[ActorGroup::None] = std::make_shared<Actor>();
	m_actors[ActorGroup::Player] = std::make_shared<Actor>();
	m_actors[ActorGroup::Enemy] = std::make_shared<Actor>(ActorName::EnemyManager);
	m_root.clearChildren();
	m_root.addChild(m_actors[ActorGroup::None]);
	m_root.addChild(m_actors[ActorGroup::Player]);
	m_root.addChild(m_actors[ActorGroup::Enemy]);
}

// �X�V 
void ActorManager::update(float deltaTime)
{
	m_root.update(deltaTime);
	collide();
	m_root.removeChildren();
}

// �`�� 
void ActorManager::draw() const
{
	m_root.draw();
}

// �A�N�^�[�̒ǉ� 
void ActorManager::addActor(ActorGroup group, const ActorPtr& actor)
{
	actor->initialize();
	m_actors[group]->addChild(actor);
}

// �A�N�^�[�̌��� 
ActorPtr ActorManager::findActor(const ActorName& name)
{
	return m_root.findChildren_NullActor(name);
}

// ���b�Z�[�W���� 
void ActorManager::handleMessage(EventMessage message, void* param)
{
	m_root.handleMessage(message, param);
}

void ActorManager::OptionalCollide(Actor* actor, ActorGroup actorGroup)
{
	actor->collideChildren(*m_actors[actorGroup]);
}


// �Փ˔��� 
void ActorManager::collide()
{
	m_actors[ActorGroup::Player]->collideChildren(*m_actors[ActorGroup::Enemy]);

}