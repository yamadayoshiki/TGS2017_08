#include "GameSelect.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"

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

	//p_World->update(deltaTime);
}

// ���̃V�[����Ԃ�     
SceneName GameSelect::Next() const
{
	return SceneName::NakayamaScene;
}

// �I��     
void GameSelect::End()
{
}