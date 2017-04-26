#include "GamePlay.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"

// コンストラクタ    
GamePlay::GamePlay(const IGameManagerPtr& gameManager, const WorldPtr& world)
	:Scene(gameManager, world) {
}

// 開始     
void GamePlay::OnStart()
{
	//プレイヤー生成
	//p_World->addActor(ActorGroup::Player, std::make_shared<Player>(p_World, GSvector2(0.0f, 0.0f), p_GameManager));
}

// 更新     
void GamePlay::OnUpdate(float deltaTime)
{
}

// 次のシーンを返す     
SceneName GamePlay::Next() const
{
	return SceneName::NakayamaScene;
}

// 終了     
void GamePlay::End()
{
}