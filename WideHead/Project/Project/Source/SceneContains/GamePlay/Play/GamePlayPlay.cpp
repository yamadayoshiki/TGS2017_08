#include "GamePlayPlay.h"
#include "../../../WorldContains/World/World.h"
#include "../../../Base/GameManagerContains/IGameManager.h"
#include "../../../Utility/InputState/InputState.h"
#include "../GamePlay.h"
#include "../../../Utility/Score/Score.h"
#include "../../../UIContains/Number/Number.h"

GamePlayPlay::GamePlayPlay()
{
}

void GamePlayPlay::OnUpdate(float deltaTime) {
	//UI数字設定
	std::dynamic_pointer_cast<GamePlay>(p_Parent.lock())->GetScoreUI().lock()->SetNum(p_GameManager->GetScore()->ReleaseScore());
	std::dynamic_pointer_cast<GamePlay>(p_Parent.lock())->GetPlayerRemainingUI().lock()->SetNum(MAX(0,p_GameManager->GetPlayerParameter().GetRemaining()));

	// 討伐可能な敵が０以下の場合クリア
	if (p_World->GetSurviverSum() <= 0) {
		isGameClear = true;
		Change(SceneName::Close);
		return;
	}

	//ポーズ切り替え
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_START) == GS_TRUE)
		Change(SceneName::Pause);
}