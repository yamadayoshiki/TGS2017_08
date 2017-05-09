#include "GameSelect.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"

// コンストラクタ    
GameSelect::GameSelect(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
}

// 開始     
void GameSelect::OnStart()
{
}

// 更新     
void GameSelect::OnUpdate(float deltaTime)
{
	gsTextPos(100, 100);
	gsDrawText("select");

	//p_World->update(deltaTime);
}

// 次のシーンを返す     
SceneName GameSelect::Next() const
{
	return SceneName::NakayamaScene;
}

// 終了     
void GameSelect::End()
{
}