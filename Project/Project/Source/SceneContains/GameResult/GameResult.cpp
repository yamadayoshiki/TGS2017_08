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


// コンストラクタ    
GameResult::GameResult(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
}

// 開始     
void GameResult::OnStart(){
	gsBindMusic(BGM_GAME_CLER);
	gsBindMusic(BGM_GAME_OVER);
	MapOrder =p_GameManager->get_MapOrder();

	if (p_GameManager->GetPlayerParameter().m_Remaining <= 0)
	{
		m_ResultTextureName = "Over";
		m_SelectTextureName = "Restart";
	}
	else
	{
		//死んでないときcsvの番号追加
		m_ResultTextureName = "Clear";
		m_SelectTextureName = "NextStage";
	}
}

// 更新     
void GameResult::OnUpdate(float deltaTime){
	/*if (p_GameManager->GetPlayerParameter().m_Remaining <= 0)
	{
		gsPlayMusic();
	}*/
	//次のステージに行くかタイトルに戻るか
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) &&
		CarsorMovement == 0) {
		if (m_ResultTextureName == "Clear") { MapOrder += 1; }
		p_GameManager->set_MapOrder(MapOrder);
		p_World->EndRequest(SceneName::GamePlay);
	}

	else if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) &&
		CarsorMovement == 1){
		MapOrder = 0;
		p_World->EndRequest(SceneName::GameTitle);
	}

	//カーソル移動
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_DOWN) ||
		p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_UP)){
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

void GameResult::OnDraw() const
{
	p_GameManager->GetRenderer2D()->DrawTexture(m_ResultTextureName, GSvector2(0, 0));
	p_GameManager->GetRenderer2D()->DrawTexture(m_SelectTextureName, GSvector2(SCREEN_SIZE.x / 2 - 128, 350));
	p_GameManager->GetRenderer2D()->DrawTexture("ReturnTitle", GSvector2(SCREEN_SIZE.x / 2 - 128, SCREEN_SIZE.y / 2 + 128));

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



