#include "GameCredit.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"

// �R���X�g���N�^    
GameCredit::GameCredit(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
}

// �J�n     
void GameCredit::OnStart()
{
}

// �X�V     
void GameCredit::OnUpdate(float deltaTime)
{
	gsTextPos(100, 100);
	gsDrawText("credit");

	if (p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN)) {
		p_World->EndRequest(SceneName::GameTitle);
	}
}
