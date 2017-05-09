#include "GamePlay.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"


// �R���X�g���N�^    
GamePlay::GamePlay(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
}

// �J�n     
void GamePlay::OnStart(){
}

// �X�V     
void GamePlay::OnUpdate(float deltaTime)
{
	gsTextPos(100, 100);
	gsDrawText("GamePlay");


	if (p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN)) {
		p_World->EndRequest(SceneName::NakayamaScene);
	}
}

// ���̃V�[����Ԃ�     
SceneName GamePlay::Next() const{
	return SceneName::NakayamaScene;
}

// �I��     
void GamePlay::End()
{
}