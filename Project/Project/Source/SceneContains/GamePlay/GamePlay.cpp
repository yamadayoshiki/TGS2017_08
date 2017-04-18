#include "GamePlay.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"

// �R���X�g���N�^    
GamePlay::GamePlay()
{
}

// �J�n     
void GamePlay::OnStart()
{
	p_World = std::make_shared<World>();
}

// �X�V     
void GamePlay::OnUpdate(float deltaTime)
{
	p_World->update(deltaTime);
}

// �`��     
void GamePlay::Draw() const
{
	p_World->Draw();
}

// ���̃V�[����Ԃ�     
SceneName GamePlay::Next() const
{
	return SceneName::NakayamaScene;
}

// �I��     
void GamePlay::End()
{
	p_World = nullptr;
}