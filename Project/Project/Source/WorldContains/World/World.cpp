#include "World.h" 
#include"../../Define/Def_Nakayama.h"
#include"../../FileReader/CsvReader.h"
#include"../../Map/Map.h"
#include "../../ActorContains/ActorManager/ActorManager.h"
#include"../../MapGenerator/MapGenerator.h"
#include "../EventMessage/EventMessage.h"

#include <iostream>

// コンストラクタ
World::World()
	:p_Actors(std::make_shared<ActorManager>()),
	m_IsEnd(false){
}

// デストラクタ
World::~World() {
	Finalize();
}

// 更新
void World::update(float deltaTime)
{
	p_Actors->update(deltaTime);
}

// 描画
void World::draw() const
{
	p_Actors->draw();
}

void World::Draw() const
{
	p_Actors->draw();
}

//終了処理
void World::Finalize()
{
	
}

// メッセージ処理 
void World::handleMessage(EventMessage message, void* param)
{
	// ワールドのメッセージ処理 
	switch (message)
	{
	case EventMessage::END_SCENE : EndRequest((const SceneName&)param);
	default:
		break;
	}

	// アクターのメッセージ処理    
	p_Actors->handleMessage(message, param);
}

// アクターの追加 
void World::addActor(ActorGroup group, const ActorPtr& actor)
{
	p_Actors->addActor(group, actor);
}

// アクターの検索
ActorPtr World::findActor(const ActorName& name)
{
	return p_Actors->findActor(name);
}

//任意の一つオブジェクトが衝突判定
void World::OptinalCollide(Actor* actor, ActorGroup actorGroup)
{
	p_Actors->OptionalCollide(actor, actorGroup);
}

// メッセージの送信
void World::sendMessage(EventMessage message, void* param)
{
	handleMessage(message, param);
}

void World::generate(const IWorldPtr world, const IGameManagerPtr& gameManager, const std::string& file_name)
{
	p_MapGenerator = std::make_shared<MapGenerator>(world, gameManager);
	p_MapGenerator->load(file_name);
	p_MapGenerator->registActor();
	p_MapGenerator->generate();

	p_MapGenerator->registMap();
}

Map & World::GetMap(){
	return p_MapGenerator->getMap();
}

bool World::IsEnd(){
	return m_IsEnd;
}

void World::EndRequest(const SceneName & name){
	m_NextScene = name;
	m_IsEnd = true;
}

void World::ResetEnd(){
	m_IsEnd = false;
}

SceneName World::NextScene(){
	return m_NextScene;
}

//Map& World::GetMap()
//{
//	return ;
//}

////マップジェネレーターの設定
//void World::setMapGenerator(MapGenerator* mapGenerator) {
//	p_MapGenerator = mapGenerator;
//}