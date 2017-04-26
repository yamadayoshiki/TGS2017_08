#include "GameTitle.h"
#include <gslib.h>

#include "../SceneName.h"

// �R���X�g���N�^    
GameTitle::GameTitle(const IGameManagerPtr& gameManager, const WorldPtr& world)
	:Scene(gameManager, world)
{
}

// �J�n     
void GameTitle::OnStart()
{
}

// �X�V     
void GameTitle::OnUpdate(float deltaTime)
{
}

// ���̃V�[����Ԃ�     
SceneName GameTitle::Next() const
{
	return SceneName::GamePlay;
}

// �I��     
void GameTitle::End()
{
}
