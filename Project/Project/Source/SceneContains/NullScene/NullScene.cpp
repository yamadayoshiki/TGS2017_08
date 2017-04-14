#include "NullScene.h"
#include "../SceneName.h"

// �R���X�g���N�^    
NullScene::NullScene()
{
}
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