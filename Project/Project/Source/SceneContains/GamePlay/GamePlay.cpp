#include "GamePlay.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"

// コンストラクタ    
GamePlay::GamePlay()
{
}

// 開始     
void GamePlay::OnStart()
{
	p_World = std::make_shared<World>();
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