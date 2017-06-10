#include "GameEnd.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"

// コンストラクタ    
GameEnd::GameEnd(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
}

// 開始     
void GameEnd::OnStart(){
	
}

// 更新     
void GameEnd::OnUpdate(float deltaTime){
	gsTextPos(100, 100);
	gsDrawText("end");

	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_A))
	{
		p_World->EndRequest(SceneName::GameTitle);
	}
}
