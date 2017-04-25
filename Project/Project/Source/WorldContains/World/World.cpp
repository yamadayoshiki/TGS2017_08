#include "World.h" 
#include"../../Define/Def_Nakayama.h"
#include"../../FileReader/CsvReader.h"
#include"../../Map/Map.h"

#include <iostream>

// コンストラクタ
World::World()
	:p_Actors(new ActorManager())
	, m_Map(Map())
{
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

void World::generate()
{
	p_MapGenerator->load("Resource/StreamingAssets/stage1.csv");
	p_MapGenerator->registActor();
	p_MapGenerator->registMap(m_Map);
	p_MapGenerator->generate();
}

//終了処理
void World::Finalize()
{
	delete p_Actors;
}

// メッセージ処理 
void World::handleMessage(EventMessage message, void* param)
{
	// ワールドのメッセージ処理 

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

//Map& World::GetMap()
//{
//	return ;
//}

//マップジェネレーターの設定
void World::setMapGenerator(MapGenerator* mapGenerator) {
	p_MapGenerator = mapGenerator;
}