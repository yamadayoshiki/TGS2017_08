#include "ActorManager.h" 
#include "../Actor/Actor.h"
#include "../ActorGroup.h"
#include "../NullActor/NullActor.h"
#include "../../CharacterContains/EnemyContains/EnemyManager/EnemyManager.h"
#include <memory>
#include <chrono>

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

void ActorManager::SetUp(IWorld * world, const IGameManagerPtr & gameManager) {
	p_EnemyManager.lock()->SetUp(world, gameManager);
}

// 初期化 
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

// 更新 
void ActorManager::update(float deltaTime) {
	p_Root->update(deltaTime);
	collide();
	p_Root->LateUpdate();
	p_Root->removeChildren_dead();
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

int ActorManager::GetSurviverSum() {
	return p_EnemyManager.lock()->GetSurviverSum();
}

//任意の衝突判定
void ActorManager::OptionalCollide(Actor* actor, ActorGroup actorGroup) {
	actor->collideChildren(*m_actors[actorGroup]);
}

// 衝突判定 
void ActorManager::collide() {
	m_actors[ActorGroup::Player]->collideChildren(*m_actors[ActorGroup::Enemy]);
	p_EnemyManager.lock()->EnemyCollide();
}