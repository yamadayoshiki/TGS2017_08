#include"yamadaScene.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include"../../ActorContains/Object/TestEnemy.h"

// コンストラクタ    
yamadaScene::yamadaScene(const IGameManagerPtr& gameManager, const WorldPtr& world)
	:Scene(gameManager, world) {
}

// 開始     
void yamadaScene::OnStart()
{
	//プレイヤー生成
	p_World->addActor(ActorGroup::Player, std::make_shared<Player>(p_World, GSvector2(0.0f, 0.0f), p_GameManager));
	//TestEnemyの生成
	//p_World->addActor(ActorGroup::Enemy, std::make_shared<TestEnemy>(p_World, GSvector2(500.0f, 500.0f), p_GameManager));
}

// 更新     
void yamadaScene::OnUpdate(float deltaTime)
{
	p_World->update(deltaTime);
}

// 次のシーンを返す     
SceneName yamadaScene::Next() const
{
	return SceneName::NakayamaScene;
}

// 終了     
void yamadaScene::End()
{
}