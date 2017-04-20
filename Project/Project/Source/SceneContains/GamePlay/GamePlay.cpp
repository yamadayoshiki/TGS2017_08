#include "GamePlay.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"

// コンストラクタ    
GamePlay::GamePlay(GameManager* GameManager)
	:p_GameManager(GameManager)
{
}

// 開始     
void GamePlay::OnStart()
{
	p_World = std::make_shared<World>();

	p_World->addActor(ActorGroup::Player, std::make_shared<Player>(p_World.get(), GSvector2(0.0f, 0.0f), p_GameManager));
}

// 更新     
void GamePlay::OnUpdate(float deltaTime)
{
	p_World->update(deltaTime);
}

// 描画     
void GamePlay::Draw() const
{
	p_World->Draw();
}

// 次のシーンを返す     
SceneName GamePlay::Next() const
{
	return SceneName::NakayamaScene;
}

// 終了     
void GamePlay::End()
{
	p_World = nullptr;
}