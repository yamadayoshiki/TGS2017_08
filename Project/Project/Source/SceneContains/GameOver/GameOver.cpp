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
	gsBindMusic(BGM_GAME_OVER);
	m_CarsorMovement = CarsorMovement::Left;
	MapOrder = p_GameManager->get_MapOrder();
	p_GameManager->GetPlayerParameter().setRemaining(3);
}

void GameOver::OnUpdate(float deltaTime)
{
	gsPlayMusic(BGM_GAME_OVER);

	//選択の更新
	SelectUpdate();

	//カーソル移動
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_LEFT) ||
		p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_RIGHT)) {
		if (m_CarsorMovement == CarsorMovement::Left)
		{
			m_CarsorMovement = CarsorMovement::Right;
		}

		else
		{
			m_CarsorMovement = CarsorMovement::Left;
		}
	}
	
}

void GameOver::OnDraw() const
{
	//リトライするか、タイトルに戻るかの描画
	p_GameManager->GetRenderer2D()->DrawTexture("Over", GSvector2(0, 0));
	p_GameManager->GetRenderer2D()->DrawTexture("Restart", GSvector2(SCREEN_SIZE.x / 2 - 400, SCREEN_SIZE.y / 2 + 178));
	p_GameManager->GetRenderer2D()->DrawTexture("PauseRT", GSvector2(SCREEN_SIZE.x / 2 + 128, SCREEN_SIZE.y / 2 + 178));

	//カーソル描画
	if (m_CarsorMovement == CarsorMovement::Left)
	{
		p_GameManager->GetRenderer2D()->DrawTexture("Cursor", GSvector2(SCREEN_SIZE.x / 2 - 470, SCREEN_SIZE.y / 2 + 190));
	}
	else
	{
		p_GameManager->GetRenderer2D()->DrawTexture("Cursor", GSvector2(SCREEN_SIZE.x / 2 + 50, SCREEN_SIZE.y / 2 + 190));
	}
}

void GameOver::End()
{
	gsStopMusic(BGM_GAME_OVER);
}

void GameOver::SelectUpdate()
{
	//次のステージに行くかタイトルに戻るか
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) == GS_FALSE) return;

	switch (m_CarsorMovement)
	{
	case CarsorMovement::Left:
		p_GameManager->set_MapOrder(MapOrder);
		p_World->EndRequest(SceneName::GamePlay);
		gsPlaySE(SE_DECITION);
		break;

	case CarsorMovement::Right:
		MapOrder = 0;
		p_World->EndRequest(SceneName::GameTitle);
		gsPlaySE(SE_DECITION);
		break;
	}
}