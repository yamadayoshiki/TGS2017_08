#include "GameTutorialPlay.h"
#include "../../../WorldContains/World/World.h"
#include "../../../Base/GameManagerContains/IGameManager.h"
#include "../../../Utility/InputState/InputState.h"
#include "../GameTutorial.h"
#include "../../../Utility/Score/Score.h"
#include "../../../UIContains/Number/Number.h"
#include "../../Elements/Guide/Guide.h"
#include "../../Elements/TargetCircle/TargetCircle.h"
#include "../../../Wall/BreakWall.h"
#include "../../../CharacterContains/EnemyContains/Entity/Enemys/Enemy05/Enemy05.h"
#include "../../../CharacterContains/EnemyContains/Entity/Enemys/Enemy12/Enemy12.h"
#include "../../../Utility/FourDirection/FourDirection.h"
#include "../../../CharacterContains/PlayerContains/Player/Player_Parameter.h"
#include "../../../Base/GameManagerContains/IGameManager.h"
#include "../../../Utility/InputState/InputState.h"
#include "../../../WorldContains/EventMessage/EventMessage.h"
#include "../../SceneManager/SceneManager.h"

GameTutorialPlay::GameTutorialPlay() {
}

void GameTutorialPlay::OnStart() {
}

void GameTutorialPlay::OnUpdate(float deltaTime) {
	switch (std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetGuide()->GetState())
	{
	case GuideState::Tutorial2:
		if (std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetBreakWall()->GetDead() == true)
			std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetGuide()->ChangeState(GuideState::Tutorial3);
		break;

	case GuideState::Tutorial3:
		if (std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetEnemy05()->GetDead() == true)
			std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetGuide()->ChangeState(GuideState::Tutorial4);
		break;

	case GuideState::Tutorial5:
		if (p_GameManager->GetPlayerParameter().getPosition().y <= 288)
			std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetGuide()->ChangeState(GuideState::Tutorial6);
		break;

	case GuideState::Tutorial6:
		if (p_GameManager->GetPlayerParameter().getChargeFlag() == true)
			std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetGuide()->ChangeState(GuideState::Tutorial7);
		break;

	case GuideState::Tutorial7:
		if (std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetEnemy12()->GetDead() == true)
			std::dynamic_pointer_cast<GameTutorial>(p_Parent.lock())->GetGuide()->ChangeState(GuideState::Tutorial8);
		break;

	case GuideState::Tutorial8:
		Change(SceneName::Close);
		return;
	}

	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_X)) {
		isGameClear = true;
		p_GameManager->GetSceneManager()->HandleMessage(EventMessage::END_SCENE, (void*)SceneName::GamePlay);
		return;
	}

	//ƒ|[ƒYØ‚è‘Ö‚¦
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_START) == GS_TRUE)
		Change(SceneName::Pause);
}

void GameTutorialPlay::OnDraw() const
{
}

void GameTutorialPlay::OnEnd() {
}
