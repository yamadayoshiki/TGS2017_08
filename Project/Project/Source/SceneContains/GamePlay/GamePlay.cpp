#include "GamePlay.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"


// コンストラクタ    
GamePlay::GamePlay(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
}

// 開始     
void GamePlay::OnStart(){
}

// 更新     
void GamePlay::OnUpdate(float deltaTime)
{
	gsTextPos(100, 100);
	gsDrawText("GamePlay");


	if (p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN)) {
		p_World->EndRequest(SceneName::NakayamaScene);
	}
}

// 次のシーンを返す     
SceneName GamePlay::Next() const{
	return SceneName::NakayamaScene;
}

// 終了     
void GamePlay::End()
{
}