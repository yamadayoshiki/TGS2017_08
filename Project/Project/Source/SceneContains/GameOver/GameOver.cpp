#include "GameOver.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"
#include "../../Define/Def_Nakayama.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include"../../MapGenerator/MapGenerator.h"
#include "../../Utility/FourDirection/FourDirection.h"

GameOver::GameOver(const IGameManagerPtr & gameManager)
	:Scene(gameManager)
{
}

void GameOver::OnStart()
{
	if (p_GameManager->GetPlayerParameter().m_Remaining <= 0) {
		p_GameManager->GetRenderer2D()->DrawTexture("Over", GSvector2(0, 0));
	}
}

void GameOver::OnUpdate(float deltaTime)
{
	//カーソル移動
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_DOWN) ||
		p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_UP)) {
		if (CarsorMovement == 0)
		{
			CarsorMovement = 1;
		}
		else
		{
			CarsorMovement = 0;
		}
	}
}

void GameOver::OnDraw() const
{
	p_GameManager->GetRenderer2D()->DrawTexture("logo", GSvector2(SCREEN_SIZE.x / 2 - 128, SCREEN_SIZE.y / 2 - 128));
	p_GameManager->GetRenderer2D()->DrawTexture("logo", GSvector2(SCREEN_SIZE.x / 2 - 128, SCREEN_SIZE.y / 2 + 128));

	//カーソル描画
	if (CarsorMovement == 0)
	{
		p_GameManager->GetRenderer2D()->DrawTexture("Cursor", GSvector2(SCREEN_SIZE.x / 2 - 178, SCREEN_SIZE.y / 2 - 100));
	}
	else
	{
		p_GameManager->GetRenderer2D()->DrawTexture("Cursor", GSvector2(SCREEN_SIZE.x / 2 - 178, SCREEN_SIZE.y / 2 + 100));
	}
}
