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

// コンストラクタ    
GameTitle::GameTitle(const IGameManagerPtr& gameManager)
	:Scene(gameManager){
	//gameManager->GetRenderer2D()->LoadTexture("logo", "Resource/Texture/UI/Title/logo.png");
}

// 開始     
void GameTitle::OnStart(){
	p_GameManager->GetPlayerParameter().setRemaining(3);
	p_GameManager->GetScore()->initialze();
	MapOrder = 1;
	
	gsBindMusic(BGM_GAME_TITLE);
	
}

// 更新
void GameTitle::OnUpdate(float deltaTime){
	gsPlayMusic();

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

