#include "GameTitleReady.h"
#include "../GameTitle.h"
#include "../../Elements/DropSprite/DropSprite.h"
#include "../../../Base/GameManagerContains/IGameManager.h"
#include "../../../Utility/InputState/InputState.h"
#include <GSmusic.h>
#include "../../../Utility/Sound/SoundName.h"
#include "../../../WorldContains/World/World.h"
#include "../../Elements/AnimationFont/AnimationFont.h"
GameTitleReady::GameTitleReady()
{
}

void GameTitleReady::OnStart() {
}

void GameTitleReady::OnUpdate(float deltaTime) {
	//Bボタンでゲームプレイへ
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_B) || p_GameManager->GetInputState()->IsKeyTrigger(GKEY_RETURN)) {
		gsPlaySE(SE_DECITION);
		Change(SceneName::Select);
	}
}

void GameTitleReady::OnEnd() {
	std::dynamic_pointer_cast<GameTitle>(p_Parent.lock())->GetTitle().lock()->Skip();
	for (int i = 0; i < 13; i++)
		std::dynamic_pointer_cast<GameTitle>(p_Parent.lock())->GetPushBMessage(i).lock()->dead();
}
