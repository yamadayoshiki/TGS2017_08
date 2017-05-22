#include "GameResult.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"

// コンストラクタ    
GameResult::GameResult(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
}

// 開始     
void GameResult::OnStart(){
	if (p_GameManager->GetPlayerParameter().m_Remaining <= 0) {
		m_Text = "GameOver";
	}
	else {
		m_Text = "GameClear";
	}
}

// 更新     
void GameResult::OnUpdate(float deltaTime){
	gsTextPos(SCREEN_SIZE.x / 2, SCREEN_SIZE.y / 2);
	gsDrawText("%s", m_Text.c_str());

	if (p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN)) {
		p_World->EndRequest(SceneName::GameTitle);
	}
}
