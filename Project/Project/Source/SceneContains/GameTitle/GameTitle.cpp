#include "GameTitle.h"
#include <gslib.h>

#include "../SceneName.h"

// コンストラクタ    
GameTitle::GameTitle(const IGameManagerPtr& gameManager)
	:Scene(gameManager)
{
}

//デフォルトコンストラクタ
GameTitle::GameTitle()
	: Scene() {}

// 開始     
void GameTitle::OnStart()
{
}

// 更新     
void GameTitle::OnUpdate(float deltaTime)
{
}

// 描画     
void GameTitle::Draw() const
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
