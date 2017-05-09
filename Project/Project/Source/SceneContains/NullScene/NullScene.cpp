#include "NullScene.h"
#include "../SceneName.h"

// �f�t�H���g�R���X�g���N�^    
NullScene::NullScene(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {}

//�R���X�g���N�^
NullScene::NullScene()
	:Scene(nullptr){}

// �`��     
void NullScene::Draw() const
{
}

// ���̃V�[����Ԃ�     
SceneName NullScene::Next() const
{
	return SceneName::None;
}
// �I��     
void NullScene::End()
{
}
// �J�n     
void NullScene::OnStart()
{
}

// �X�V     
void NullScene::OnUpdate(float deltaTime)
{
}

void NullScene::OnEnd()
{
}
