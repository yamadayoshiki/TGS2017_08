#include "GameCredit.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"

// コンストラクタ    
GameCredit::GameCredit(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
}

// 開始     
void GameCredit::OnStart()
{
}

// 更新     
void GameCredit::OnUpdate(float deltaTime)
{
	gsTextPos(100, 100);
	gsDrawText("credit");

	//p_World->update(deltaTime);
}

// 次のシーンを返す     
SceneName GameCredit::Next() const
{
	return SceneName::NakayamaScene;
}

// 終了     
void GameCredit::End()
{
}