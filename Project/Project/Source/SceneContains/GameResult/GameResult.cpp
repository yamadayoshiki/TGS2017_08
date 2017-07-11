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
	//p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World.get(), p_GameManager, m_SceneName));

	//BGMの設定
	gsBindMusic(BGM_GAME_CLER);
	//BGM再生
	gsPlayMusic();
}

// 更新     
void GameResult::OnUpdate(float deltaTime) {

	//選択の更新
	SelectUpdate();

}

void GameResult::OnDraw() const
{
	//次のステージに行くかタイトルに戻るか
	p_GameManager->GetRenderer2D()->DrawTexture("game_back", GSvector2(0, 0));

	p_GameManager->GetRenderer2D()->DrawTexture("BigBlock", GSvector2(550, 300));
	p_GameManager->GetRenderer2D()->DrawTexture("Platform", GSvector2(625, 450));
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
	//次のステージがない場合ゲームクリアへ遷移
	if ((this->MapOrder == 6)) {
		p_World->EndRequest(SceneName::GameTitle);
		return;
	}
}
