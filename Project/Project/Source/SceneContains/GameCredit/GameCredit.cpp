#include "GameCredit.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"

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

	//p_World->update(deltaTime);
}

// ���̃V�[����Ԃ�     
SceneName GameCredit::Next() const
{
	return SceneName::NakayamaScene;
}

// �I��     
void GameCredit::End()
{
}