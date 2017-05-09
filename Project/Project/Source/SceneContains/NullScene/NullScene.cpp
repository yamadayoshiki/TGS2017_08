#include "NullScene.h"
#include "../SceneName.h"

// デフォルトコンストラクタ    
NullScene::NullScene(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {}

//コンストラクタ
NullScene::NullScene()
	:Scene(nullptr){}

// 描画     
void NullScene::Draw() const
{
}

// 次のシーンを返す     
SceneName NullScene::Next() const
{
	return SceneName::None;
}
// 終了     
void NullScene::End()
{
}
// 開始     
void NullScene::OnStart()
{
}

// 更新     
void NullScene::OnUpdate(float deltaTime)
{
}

void NullScene::OnEnd()
{
}
