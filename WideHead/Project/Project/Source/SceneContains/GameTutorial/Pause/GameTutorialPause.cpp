#include "GameTutorialPause.h"
#include "../../../Utility/Sound/SoundName.h"
#include "../GameTutorial.h"
#include <gslib.h>
#include "../../../UIContains/Button/Button.h"
#include "../../../UIContains/Sprite/Sprite.h"
#include "../../../Base/GameManagerContains/IGameManager.h"
#include "../../../Utility/InputState/InputState.h"
#include "../../Elements/FlashSprite/FlashSprite.h"
GameTutorialPause::GameTutorialPause() {
}

void GameTutorialPause::OnStart() {
	p_Parent.lock()->StopWorld();
	gsPlaySE(SE_PAUSE_OPEN);
	std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetButtonUI().lock()->ChangeDisplayMode(DisplayMode::Display);
	std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetPauseBack().lock()->ChangeDisplayMode(DisplayMode::Display);
	std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetSkipUI()->ChangeDisplayMode(DisplayMode::NonDisplay);
}

void GameTutorialPause::OnUpdate(float deltaTime) {
	std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetButtonUI().lock()->update(deltaTime);
	std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetButtonUI().lock()->LateUpdate();

	//ƒ|[ƒYØ‚è‘Ö‚¦
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_START) == GS_TRUE)
		Change(SceneName::Play);
}

void GameTutorialPause::OnEnd() {
	p_Parent.lock()->Restart();
	gsPlaySE(SE_PAUSE_OPEN);
	std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetButtonUI().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetPauseBack().lock()->ChangeDisplayMode(DisplayMode::NonDisplay);
	std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetSkipUI()->ChangeDisplayMode(DisplayMode::Display);
}
