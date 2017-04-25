#include "NullScene.h"
#include "../SceneName.h"

// �f�t�H���g�R���X�g���N�^    
NullScene::NullScene(const IGameManagerPtr& gameManager, const WorldPtr& world)
	:Scene(gameManager,world) {}

//�R���X�g���N�^
NullScene::NullScene()
	:Scene(nullptr,nullptr){}

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