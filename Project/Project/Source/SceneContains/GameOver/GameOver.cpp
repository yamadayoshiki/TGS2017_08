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
#include "../../DrawManager/DrawManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"

GameOver::GameOver(const IGameManagerPtr & gameManager)
	:Scene(gameManager){
	//登録
	m_OrverNum = p_GameManager->GetDrawManager()->RegisterDefaultParam("Over", p_OverParam, DrawOrder::UI);
	p_OverParam->m_Position = GSvector2(0, 0);
	m_ResultNum = p_GameManager->GetDrawManager()->RegisterDefaultParam("Restart", p_ResultParam, DrawOrder::UI);
	p_ResultParam->m_Position = GSvector2(SCREEN_SIZE.x / 2 - 400, SCREEN_SIZE.y / 2 + 178);
	m_PauseRTNum = p_GameManager->GetDrawManager()->RegisterDefaultParam("PauseRT", p_PauseRTParam, DrawOrder::UI);
	p_PauseRTParam->m_Position = GSvector2(SCREEN_SIZE.x / 2 + 128, SCREEN_SIZE.y / 2 + 178);
	m_CursorNum = p_GameManager->GetDrawManager()->RegisterDefaultParam("Cursor", p_CursorParam, DrawOrder::UI);
	p_CursorParam->m_Position = GSvector2(SCREEN_SIZE.x / 2 - 470, SCREEN_SIZE.y / 2 + 190);
	//非表示設定
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_OrverNum, DisplayMode::NonDisplay);
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_ResultNum, DisplayMode::NonDisplay);
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_PauseRTNum, DisplayMode::NonDisplay);
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_CursorNum, DisplayMode::NonDisplay);
}

void GameOver::OnStart(){
	gsBindMusic(BGM_GAME_OVER);
	m_CarsorMovement = CarsorMovement::Left;
	MapOrder = p_GameManager->get_MapOrder();
	p_GameManager->GetPlayerParameter().setRemaining(3);
	//表示設定
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_OrverNum, DisplayMode::Display);
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_ResultNum, DisplayMode::Display);
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_PauseRTNum, DisplayMode::Display);
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_CursorNum, DisplayMode::Display);
}

void GameOver::OnUpdate(float deltaTime)
{
	gsPlayMusic();

	//選択の更新
	SelectUpdate();

	//カーソル移動
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_LEFT) ||
		p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_RIGHT)) {
		if (m_CarsorMovement == CarsorMovement::Left) {
			m_CarsorMovement = CarsorMovement::Right;
			p_CursorParam->m_Position = GSvector2(SCREEN_SIZE.x / 2 - 470, SCREEN_SIZE.y / 2 + 190);
		}

		else {
			m_CarsorMovement = CarsorMovement::Left;
			p_CursorParam->m_Position = GSvector2(SCREEN_SIZE.x / 2 - 470, SCREEN_SIZE.y / 2 + 190);
		}
	}
}

void GameOver::OnDraw() const {
}

void GameOver::End(){
	gsStopMusic();
	//非表示設定
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_OrverNum, DisplayMode::NonDisplay);
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_ResultNum, DisplayMode::NonDisplay);
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_PauseRTNum, DisplayMode::NonDisplay);
	p_GameManager->GetDrawManager()->ChageDisplayMode(m_CursorNum, DisplayMode::NonDisplay);
}

void GameOver::SelectUpdate(){
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