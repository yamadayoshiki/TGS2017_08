#include "GameOver.h"
#include <gslib.h>
#include<GSmusic.h>
#include "../SceneName.h"
#include "../../UIContains/UIManager/UIManager.h"
#include "../../ActorContains/ActorGroup.h"
#include "../../WorldContains/World/World.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include"../../Utility/Score/Score.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"
#include"../../Utility/InputState/InputState.h"
#include"../../Utility/Sound/SoundName.h"


GameOver::GameOver(const IGameManagerPtr & gameManager)
	:Scene(gameManager)
{
	
}

void GameOver::OnStart()
{
	gsBindMusic(BGM_GAME_CLER);
}

void GameOver::OnUpdate(float deltaTime)
{
	gsPlayMusic(BGM_GAME_CLER);

		if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B)){
			gsPlaySE(SE_DECITION);
			MapOrder = 0;
			p_World->EndRequest(SceneName::GameTitle);
		}
	
}

void GameOver::OnDraw() const
{
	p_GameManager->GetRenderer2D()->DrawTexture("GameClear",GSvector2(SCREEN_SIZE.x/2 - 375, SCREEN_SIZE.y/2 - 125));
	p_GameManager->GetRenderer2D()->DrawTexture("Start", GSvector2(400, 600));
}

void GameOver::End()
{
	gsStopMusic(BGM_GAME_CLER);
}
