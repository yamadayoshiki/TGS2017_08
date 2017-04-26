#include "ActorManager.h" 
#include "../ActorGroup.h"
#include <memory>

// コンストラクタ 
ActorManager::ActorManager() {
	initialize();
}

// 初期化 
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

// 更新 
void ActorManager::update(float deltaTime)
{
	m_root.update(deltaTime);
	collide();
	m_root.removeChildren();
}

// 描画 
void ActorManager::draw() const
{
	m_root.draw();
}

// アクターの追加 
void ActorManager::addActor(ActorGroup group, const ActorPtr& actor)
{
	actor->initialize();
	m_actors[group]->addChild(actor);
}

// アクターの検索 
ActorPtr ActorManager::findActor(const ActorName& name)
{
	return m_root.findChildren_NullActor(name);
}

// メッセージ処理 
void ActorManager::handleMessage(EventMessage message, void* param)
{
	m_root.handleMessage(message, param);
}

void ActorManager::OptionalCollide(Actor* actor, ActorGroup actorGroup)
{
	actor->collideChildren(*m_actors[actorGroup]);
}


// 衝突判定 
void ActorManager::collide()
{
	m_actors[ActorGroup::Player]->collideChildren(*m_actors[ActorGroup::Enemy]);

}