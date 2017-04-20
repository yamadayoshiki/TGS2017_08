#include "GamePlay.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"

// �R���X�g���N�^    
GamePlay::GamePlay(GameManager* GameManager)
	:p_GameManager(GameManager)
{
}

// �J�n     
void GamePlay::OnStart()
{
	p_World = std::make_shared<World>();

	p_World->addActor(ActorGroup::Player, std::make_shared<Player>(p_World.get(), GSvector2(0.0f, 0.0f), p_GameManager));
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