#include "GameTitle.h"
#include <gslib.h>

#include "../SceneName.h"

// コンストラクタ    
GameTitle::GameTitle(const IGameManagerPtr& gameManager, const WorldPtr& world)
	:Scene(gameManager, world)
{
}

// 開始     
void GameTitle::OnStart()
{
}

// 更新     
void GameTitle::OnUpdate(float deltaTime)
{
}

// 次のシーンを返す     
SceneName GameTitle::Next() const
{
	return SceneName::GamePlay;
}

// 終了     
void GameTitle::End()
{
}
