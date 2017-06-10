#include "ActorManager.h" 
#include "../Actor/Actor.h"
#include "../ActorGroup.h"
#include "../NullActor/NullActor.h"
#include <memory>

// コンストラクタ 
ActorManager::ActorManager() {
	p_Root = std::make_unique<Actor>();
	initialize();
}

// デストラクタ
ActorManager::~ActorManager() {
	m_actors.clear();
	p_Root->clearChildren();
}

// 初期化 
void ActorManager::initialize() {
	m_actors[ActorGroup::None] = std::make_shared<Actor>();
	m_actors[ActorGroup::UI] = std::make_shared<Actor>();
	m_actors[ActorGroup::Player] = std::make_shared<Actor>(ActorName::PlayerManager);
	m_actors[ActorGroup::Enemy] = std::make_shared<Actor>(ActorName::EnemyManager);
	// 描画順は下から
	p_Root->clearChildren();
	p_Root->addChild(m_actors[ActorGroup::None]);
	p_Root->addChild(m_actors[ActorGroup::UI]);
	p_Root->addChild(m_actors[ActorGroup::Player]);
	p_Root->addChild(m_actors[ActorGroup::Enemy]);
}

// 更新 
void ActorManager::update(float deltaTime) {
	p_Root->update(deltaTime);
	collide();
	p_Root->removeChildren();
}

// 描画 
void ActorManager::draw() const {
	p_Root->draw();
}

// アクターの追加 
void ActorManager::addActor(ActorGroup group, const ActorPtr& actor) {
	//初期化
	actor->initialize();
	//追加
	m_actors[group]->addChild(actor);
}

// アクターの検索 
ActorPtr ActorManager::findActor(const ActorName& name) {
	return p_Root->findChildren_NullActor(name);
}

// メッセージ処理 
void ActorManager::handleMessage(EventMessage message, void* param) {
	p_Root->handleMessage(message, param);
}

int ActorManager::getCount(ActorGroup group) const {
	return m_actors.at(group)->getCount();
}

//任意の衝突判定
void ActorManager::OptionalCollide(Actor* actor, ActorGroup actorGroup) {
	actor->collideChildren(*m_actors[actorGroup]);
}

// 衝突判定 
void ActorManager::collide() {
	m_actors[ActorGroup::Player]->collideChildren(*m_actors[ActorGroup::Enemy]);
}