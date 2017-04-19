#include "NaganoScene.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include "../../ActorContains/ActorGroup.h"
#include "../../ActorContains/Object/TestObj.h"
#include "../../ActorContains/Object/TestEnemy.h"

// �R���X�g���N�^    
NaganoScene::NaganoScene()
{
}

// �J�n     
void NaganoScene::OnStart()
{
	p_World = std::make_shared<World>();
	p_World->addActor(ActorGroup::Player, std::make_shared<TestObj>(p_World.get(), GSvector2(0, 0)));
	p_World->addActor(ActorGroup::None, std::make_shared<TestEnemy>(p_World.get(), GSvector2(5, 0)));
}

// �X�V     
void NaganoScene::OnUpdate(float deltaTime)
{
	p_World->update(deltaTime);
}

// �`��     
void NaganoScene::Draw() const
{
	p_World->Draw();
}

// ���̃V�[����Ԃ�     
SceneName NaganoScene::Next() const
{
	return SceneName::GameTitle;
}

// �I��     
void NaganoScene::End()
{
	p_World = nullptr;
}