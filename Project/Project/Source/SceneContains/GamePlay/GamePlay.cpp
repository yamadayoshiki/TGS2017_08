#include "GamePlay.h"

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

// コンストラクタ    
GamePlay::GamePlay(const IGameManagerPtr& gameManager)
	:Scene(gameManager) {
	gameManager->GetRenderer2D()->LoadTexture("game_back", "Resource/Texture/UI/Play/back_ground.png");
	p_GameManager->GetRenderer2D()->LoadTexture("chip", "Resource/Texture/wall.png");
}

// 開始     
void GamePlay::OnStart() {
	//マップデータによる生成
	p_World->generate(p_World, p_GameManager, "Resource/StreamingAssets/stage1.csv");

	std::unordered_map<FourDirection, TileData> tmp = p_World->GetMap()->GetAroundTile(GSvector2(70, 90));
}

// 更新     
void GamePlay::OnUpdate(float deltaTime) {
	//ポーズ
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_START) == GS_TRUE)
	{
		PauseFlag = !PauseFlag;
	}

	// Enterキーを押下、もしくは討伐可能な敵が０以下の場合クリア
	if (p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN) || p_World->GetSurviverSum() <= 0) {
		p_World->EndRequest(SceneName::GameResult);
	}
}

void GamePlay::OnDraw() const {
	p_GameManager->GetRenderer2D()->DrawTexture("game_back", GSvector2(0, 0));

	p_World->GetMap()->draw();

	// UI描画
	p_GameManager->GetPlayerParameter().DrawRemaining(p_GameManager->GetRenderer2D());
	p_GameManager->GetPlayerParameter().DrawCombo(p_GameManager->GetRenderer2D());
	gsFontParameter(GS_FONT_BOLD, 50, "HG明朝B");
	gsTextPos(900, 50);
	gsDrawText("あと %d 体", p_World->GetSurviverSum());
	gsFontParameter(GS_FONT_BOLD, 20, "HG明朝B");
}
