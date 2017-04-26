#include "GamePlay.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"

// �R���X�g���N�^    
GamePlay::GamePlay(const IGameManagerPtr& gameManager, const WorldPtr& world)
	:Scene(gameManager, world) {
}

// �J�n     
void GamePlay::OnStart()
{
	//�v���C���[����
	//p_World->addActor(ActorGroup::Player, std::make_shared<Player>(p_World, GSvector2(0.0f, 0.0f), p_GameManager));
}

// �X�V     
void GamePlay::OnUpdate(float deltaTime)
{
}

// ���̃V�[����Ԃ�     
SceneName GamePlay::Next() const
{
	return SceneName::NakayamaScene;
}

// �I��     
void GamePlay::End()
{
}