#include"yamadaScene.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include"../../ActorContains/Object/TestEnemy.h"

// �R���X�g���N�^    
yamadaScene::yamadaScene(const IGameManagerPtr& gameManager, const WorldPtr& world)
	:Scene(gameManager, world) {
}

// �J�n     
void yamadaScene::OnStart()
{
	//�v���C���[����
	p_World->addActor(ActorGroup::Player, std::make_shared<Player>(p_World, GSvector2(0.0f, 0.0f), p_GameManager));
	//TestEnemy�̐���
	//p_World->addActor(ActorGroup::Enemy, std::make_shared<TestEnemy>(p_World, GSvector2(500.0f, 500.0f), p_GameManager));
}

// �X�V     
void yamadaScene::OnUpdate(float deltaTime)
{
	p_World->update(deltaTime);
}

// ���̃V�[����Ԃ�     
SceneName yamadaScene::Next() const
{
	return SceneName::NakayamaScene;
}

// �I��     
void yamadaScene::End()
{
}