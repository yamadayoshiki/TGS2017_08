#include "GameCredit.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"

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

	if (p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN)) {
		p_World->EndRequest(SceneName::GameTitle);
	}
}
