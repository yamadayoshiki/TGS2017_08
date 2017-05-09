#include "GameTitle.h"
#include <gslib.h>

#include "../SceneName.h"
#include "../../UIContains/UIManager/Base/UIManager.h"
#include "../../ActorContains/ActorGroup.h"
#include"../../WorldContains/World/World.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"

// �R���X�g���N�^    
GameTitle::GameTitle(const IGameManagerPtr& gameManager)
	:Scene(gameManager)
{
}

// �J�n     
void GameTitle::OnStart()
{
	// UI�̐���
	p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World, p_GameManager, m_SceneName));
}

// �X�V     
void GameTitle::OnUpdate(float deltaTime)
{
	gsTextPos(100, 100);
	gsDrawText("title");
}

// �I��     
void GameTitle::End()
{
}
