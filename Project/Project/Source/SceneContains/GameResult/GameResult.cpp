#include "GameResult.h"

#include <gslib.h>
#include<GSmusic.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include"../../ActorContains/ActorGroup.h"
#include"../../Utility/Rederer2D/Renderer2D.h"
#include"../../CharacterContains/PlayerContains/Player/Player.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Define/Def_Nagano.h"
#include"../../Utility/Sound/SoundName.h"
#include"../../Utility/Score/Score.h"


// コンストラクタ    
GameResult::GameResult(const IGameManagerPtr& gameManager)
	:Scene(gameManager),
	m_ScorePosition{ 0.0f,0.0f }
{
	StageRankNolma[0][(int)Rank::RankS] = 300;
	StageRankNolma[0][(int)Rank::RankA] = 250;
	StageRankNolma[0][(int)Rank::RankB] = 200;
	StageRankNolma[0][(int)Rank::RankC] = 100;

	StageRankNolma[1][(int)Rank::RankS] = 700;
	StageRankNolma[1][(int)Rank::RankA] = 550;
	StageRankNolma[1][(int)Rank::RankB] = 400;
	StageRankNolma[1][(int)Rank::RankC] = 300;

	StageRankNolma[2][(int)Rank::RankS] = 1000;
	StageRankNolma[2][(int)Rank::RankA] = 900;
	StageRankNolma[2][(int)Rank::RankB] = 800;
	StageRankNolma[2][(int)Rank::RankC] = 750;

	StageRankNolma[3][(int)Rank::RankS] = 1100;
	StageRankNolma[3][(int)Rank::RankA] = 1050;
	StageRankNolma[3][(int)Rank::RankB] = 950;
	StageRankNolma[3][(int)Rank::RankC] = 850;

	StageRankNolma[4][(int)Rank::RankS] = 1250;
	StageRankNolma[4][(int)Rank::RankA] = 1150;
	StageRankNolma[4][(int)Rank::RankB] = 1050;
	StageRankNolma[4][(int)Rank::RankC] = 950;

	StageRankNolma[5][(int)Rank::RankS] = 1300;
	StageRankNolma[5][(int)Rank::RankA] = 1200;
	StageRankNolma[5][(int)Rank::RankB] = 1100;
	StageRankNolma[5][(int)Rank::RankC] = 1000;

	StageRankNolma[6][(int)Rank::RankS] = 1350;
	StageRankNolma[6][(int)Rank::RankA] = 1250;
	StageRankNolma[6][(int)Rank::RankB] = 1150;
	StageRankNolma[6][(int)Rank::RankC] = 1050;

	StageRankNolma[7][(int)Rank::RankS] = 1400;
	StageRankNolma[7][(int)Rank::RankA] = 1300;
	StageRankNolma[7][(int)Rank::RankB] = 1200;
	StageRankNolma[7][(int)Rank::RankC] = 1100;
}

// 開始     
void GameResult::OnStart() {
	MapOrder = p_GameManager->get_MapOrder();
	m_ScorePosition = GSvector2(550, 250);

	m_CarsorMovement = CarsorMovement::Left;

	//BGMの設定
	gsBindMusic(BGM_GAME_CLER);
	//BGM再生
	gsPlayMusic();
}

// 更新     
void GameResult::OnUpdate(float deltaTime) {

	//選択の更新
	SelectUpdate();

	//カーソル移動
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_LEFT) ||
		p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_RIGHT)) {
		if (m_CarsorMovement == CarsorMovement::Left)		{
			m_CarsorMovement = CarsorMovement::Right;
		}
		else{
			m_CarsorMovement = CarsorMovement::Left;
		}
	}
}

void GameResult::OnDraw() const
{
	//次のステージに行くかタイトルに戻るか
	p_GameManager->GetRenderer2D()->DrawTexture("Clear", GSvector2(0, 0));
	p_GameManager->GetRenderer2D()->DrawTexture("NextStage", GSvector2(SCREEN_SIZE.x / 2 - 400, SCREEN_SIZE.y / 2 + 178));
	p_GameManager->GetRenderer2D()->DrawTexture("ReturnTitle", GSvector2(SCREEN_SIZE.x / 2 + 128, SCREEN_SIZE.y / 2 + 178));

	//カーソル描画
	if (m_CarsorMovement == CarsorMovement::Left)
	{
		p_GameManager->GetRenderer2D()->DrawTexture("Cursor", GSvector2(SCREEN_SIZE.x / 2 - 470, SCREEN_SIZE.y / 2 + 190));
	}
	else
	{
		p_GameManager->GetRenderer2D()->DrawTexture("Cursor", GSvector2(SCREEN_SIZE.x / 2 + 50, SCREEN_SIZE.y / 2 + 190));
	}

	//リザルトスコアの描画
	p_GameManager->GetScore()->draw();
	p_GameManager->GetScore()->setPosition(GSvector2(200, 200));
	
		int StageIndex = MapOrder;
		if (p_GameManager->GetScore()->ReleaseScore() >= StageRankNolma[StageIndex][(int)Rank::RankS])
		{
			p_GameManager->GetRenderer2D()->DrawTexture("RankS", m_ScorePosition);
		}
		else if (p_GameManager->GetScore()->ReleaseScore() >= StageRankNolma[StageIndex][(int)Rank::RankA])
		{
			p_GameManager->GetRenderer2D()->DrawTexture("RankA", m_ScorePosition);
		}
		else if (p_GameManager->GetScore()->ReleaseScore() >= StageRankNolma[StageIndex][(int)Rank::RankB])
		{
			p_GameManager->GetRenderer2D()->DrawTexture("RankB", m_ScorePosition);
		}
		else if (p_GameManager->GetScore()->ReleaseScore() >= StageRankNolma[StageIndex][(int)Rank::RankC])
		{
			p_GameManager->GetRenderer2D()->DrawTexture("RankC", m_ScorePosition);
		}
	
}

void GameResult::End()
{
	gsStopMusic();
}

//選択の更新
void GameResult::SelectUpdate()
{
	//次のステージに行くかタイトルに戻るか
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) == GS_FALSE) return;
	//次のステージがない場合ゲームクリアへ遷移
	if ((isGameClear == true) && (this->MapOrder == 7)) {
		p_World->EndRequest(SceneName::GameOver);
		return;
	}

	switch (m_CarsorMovement)
	{
	case CarsorMovement::Left:
		MapOrder += 1;
		p_GameManager->set_MapOrder(MapOrder);
		p_World->EndRequest(SceneName::GamePlay);
		gsPlaySE(SE_DECITION);
		break;

	case CarsorMovement::Right:
		MapOrder = 0;
		p_World->EndRequest(SceneName::GameTitle);
		gsPlaySE(SE_BACK);
		break;
	}
}
