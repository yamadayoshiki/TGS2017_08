#include "World.h" 

// コンストラクタ
World::World()
	:p_Actors(new ActorManager())
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