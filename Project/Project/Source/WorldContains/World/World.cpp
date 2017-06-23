#include "World.h" 
#include"../../Define/Def_Nakayama.h"
#include"../../FileReader/CsvReader.h"
#include"../../Map/Map.h"
#include "../../ActorContains/ActorManager/ActorManager.h"
#include"../../MapGenerator/MapGenerator.h"
#include "../EventMessage/EventMessage.h"
#include "../../CharacterContains/EnemyContains/Entity/Enemys/Base/EnemyBase.h"
#include "../../CharacterContains/Factory/CharacterFactory.h"
#include <iostream>

// コンストラクタ
World::World()
	:p_Actors(std::make_shared<ActorManager>()),
	m_IsEnd(false),
	m_Target()
{
	m_Target[0] = ActorName::Enemy_05;
	m_Target[1] = ActorName::Enemy_05;
	m_Target[2] = ActorName::Enemy_06;
	m_Target[3] = ActorName::Enemy_09;
	m_Target[4] = ActorName::Enemy_05;
	m_Target[5] = ActorName::Enemy_05;
	m_Target[6] = ActorName::Enemy_05;
	m_Target[7] = ActorName::Enemy_08;
}

// デストラクタ
World::~World() {
	Finalize();
}

// 更新
void World::update(float deltaTime) {
	p_Actors->update(deltaTime);
}

// 描画
void World::draw() const {
	p_Actors->draw();
}

//終了処理
void World::Finalize() {
}

// メッセージ処理 
void World::handleMessage(EventMessage message, void* param) {
	// ワールドのメッセージ処理 
	switch (message)
	{
	case EventMessage::END_SCENE: EndRequest((const SceneName&)param);
	default:
		break;
	}

	// アクターのメッセージ処理    
	p_Actors->handleMessage(message, param);
}

// アクターの追加 
void World::addActor(ActorGroup group, const ActorPtr& actor) {
	p_Actors->addActor(group, actor);
}

// アクターの検索
ActorPtr World::findActor(const ActorName& name) {
	return p_Actors->findActor(name);
}

//任意の一つオブジェクトが衝突判定
void World::OptinalCollide(Actor* actor, ActorGroup actorGroup) {
	p_Actors->OptionalCollide(actor, actorGroup);
}

// メッセージの送信
void World::sendMessage(EventMessage message, void* param) {
	handleMessage(message, param);
}

// メッセージの送信(指定アクター)
void World::sendMessage(EventMessage message, Actor& actor, void* param) {
	actor.handleMessage(message, param);
}

//生成
void World::generate(const IWorldPtr world, const IGameManagerPtr& gameManager, const std::string& file_name){
	p_MapGenerator->load(file_name);
	p_MapGenerator->registMap();
	p_MapGenerator->generate();
}

//マップの取得
MapPtr World::GetMap() {
	return p_MapGenerator->getMap();
}

//キャラクター工場の設定
void World::SetCharacterFactory(CharacterFactory * characterFactory){
	p_CharacterFactory.reset(characterFactory);
}

//キャラクター工場の取得
CharacterFactory * World::GetCharacterFactory() const{
	return p_CharacterFactory.get();
}

void World::SetMapGenerator(const IWorldPtr& world, const IGameManagerPtr& gameManager){
	p_MapGenerator = std::make_shared<MapGenerator>(world,gameManager);
}

bool World::IsEnd() {
	return m_IsEnd;
}

void World::EndRequest(const SceneName & name) {
	m_NextScene = name;
	m_IsEnd = true;
}

void World::ResetEnd() {
	m_IsEnd = false;
}

SceneName World::NextScene() {
	return m_NextScene;
}

int World::GetSurviverSum(int mapOrder) {
	int sum = 0;
	/*findActor(ActorName::EnemyManager)->eachChildren([&](Actor& child) {
		EnemyBase* enemy = dynamic_cast<EnemyBase*>(&child);
		if (enemy->CanDead() && !enemy->GetHitPoint().IsDead()) { sum++; }
	});
	return sum;*/

	//特定の敵を倒したら次のステージに進む
	findActor(ActorName::EnemyManager)->eachChildren([&](Actor& child)
	{
		if (child.getName() == m_Target[mapOrder])
		{
			EnemyBase* l_Enemy = dynamic_cast<EnemyBase*>(&child);
			if (l_Enemy->CanDead() && !l_Enemy->GetHitPoint().IsDead())
			{
				sum += 1;
			}
		}
		
	});
	
	return sum;
}