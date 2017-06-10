#include "GameSelect.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../../UIContains/UIManager/UIManager.h"

// �R���X�g���N�^    
GameSelect::GameSelect(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
}

// �J�n     
void GameSelect::OnStart()
{
}

// �X�V     
void GameSelect::OnUpdate(float deltaTime)
{
	gsTextPos(100, 100);
	gsDrawText("select");

	if (p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN) || p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B)) {
		p_World->EndRequest(SceneName::GamePlay);
	}
}
