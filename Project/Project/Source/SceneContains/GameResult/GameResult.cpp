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
#include"../../UIContains/UIManager/UIManager.h"


// コンストラクタ    
GameResult::GameResult(const IGameManagerPtr& gameManager)
	:Scene(gameManager),
	m_ScorePosition{ 0.0f,0.0f }
{
	
}

// 開始     
void GameResult::OnStart() {
	MapOrder = p_GameManager->get_MapOrder();
	m_ScorePosition = GSvector2(550, 250);

	// UIの生成
	p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World.get(), p_GameManager, m_SceneName));

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
	p_GameManager->GetRenderer2D()->DrawTexture("game_back", GSvector2(0, 0));
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
	p_GameManager->GetScore()->setPosition(GSvector2(200, 200));
	p_GameManager->GetScore()->draw(p_GameManager->GetRenderer2D());
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
	if ((this->MapOrder == 6)) {
		p_World->EndRequest(SceneName::GameTitle);
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
