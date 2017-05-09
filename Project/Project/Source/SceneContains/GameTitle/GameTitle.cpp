#include "GameTitle.h"
#include <gslib.h>

#include "../SceneName.h"
#include "../../UIContains/UIManager/Base/UIManager.h"
#include "../../ActorContains/ActorGroup.h"
#include"../../WorldContains/World/World.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"

// コンストラクタ    
GameTitle::GameTitle(const IGameManagerPtr& gameManager)
	:Scene(gameManager)
{
}

// 開始     
void GameTitle::OnStart()
{
	// UIの生成
	p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World, p_GameManager, m_SceneName));
}

// 更新     
void GameTitle::OnUpdate(float deltaTime)
{
	gsTextPos(100, 100);
	gsDrawText("title");
}

// 終了     
void GameTitle::End()
{
}
