#include "GameTitle.h"
#include <gslib.h>

#include "../SceneName.h"

// �R���X�g���N�^    
GameTitle::GameTitle(const IGameManagerPtr& gameManager)
	:Scene(gameManager)
{
}

//�f�t�H���g�R���X�g���N�^
GameTitle::GameTitle()
	: Scene() {}

// �J�n     
void GameTitle::OnStart()
{
}

// �X�V     
void GameTitle::OnUpdate(float deltaTime)
{
}

// �`��     
void GameTitle::Draw() const
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
