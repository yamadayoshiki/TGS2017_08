#include "GameTitle.h"
#include <gslib.h>

#include "../SceneName.h"
#include "../../UIContains/UIManager/UIManager.h"
#include "../../ActorContains/ActorGroup.h"
#include"../../WorldContains/World/World.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include"../../Utility/Score/Score.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"
#include"../../Utility/InputState/InputState.h"
#include"../../Utility/Sound/SoundName.h"

#include<GSmusic.h>

// �R���X�g���N�^    
GameTitle::GameTitle(const IGameManagerPtr& gameManager)
	:Scene(gameManager){
	
}

// �J�n     
void GameTitle::OnStart(){
	p_GameManager->GetPlayerParameter().setRemaining(3);
	p_GameManager->GetScore()->initialze();
	MapOrder = 0;
	
	gsBindMusic(BGM_GAME_TITLE);
	gsPlayMusic();
}

// �X�V
void GameTitle::OnUpdate(float deltaTime){

	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B)) {
		gsPlaySE(SE_DECITION);
		p_World->EndRequest(SceneName::GamePlay);
	}
}

void GameTitle::OnDraw()const
{
	p_GameManager->GetRenderer2D()->DrawTexture("Title", GSvector2(0, 0));
	p_GameManager->GetRenderer2D()->DrawTexture("WideHead", GSvector2(300, 300));
	p_GameManager->GetRenderer2D()->DrawTexture("Start", GSvector2(400, 600));
}

void GameTitle::End()
{
	gsStopMusic();
	p_GameManager->set_MapOrder(MapOrder);
}

