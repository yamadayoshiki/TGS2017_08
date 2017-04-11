#include "ActorManager.h" 
#include "../ActorGroup.h"

// �R���X�g���N�^ 
ActorManager::ActorManager()
{
	initialize();
}

// ������ 
void ActorManager::initialize()
{
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
	actor->collideChidren(*m_actors[actorGroup]);
}


// �Փ˔��� 
void ActorManager::collide()
{
}