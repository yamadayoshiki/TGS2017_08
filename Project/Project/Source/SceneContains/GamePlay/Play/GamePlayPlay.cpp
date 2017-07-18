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

void GamePlayPlay::OnStart() {

}

void GamePlayPlay::OnUpdate(float deltaTime) {
	//UI�����ݒ�
	std::dynamic_pointer_cast<GamePlay>(p_Parent.lock())->GetScoreUI().lock()->SetNum(p_GameManager->GetScore()->ReleaseScore());
	std::dynamic_pointer_cast<GamePlay>(p_Parent.lock())->GetPlayerRemainingUI().lock()->SetNum(p_GameManager->GetPlayerParameter().GetRemaining());

	//�|�[�Y�؂�ւ�
	if (p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_START) == GS_TRUE)
		Change(SceneName::Pause);

	// �����\�ȓG���O�ȉ��̏ꍇ�N���A
	if (p_World->GetSurviverSum(MapOrder) <= 0 || p_GameManager->GetInputState()->IsPadStateTrigger(GS_XBOX_PAD_X)) {
		isGameClear = true;
		p_World->EndRequest(SceneName::GameResult);
	}
}

void GamePlayPlay::OnDraw() const
{
}

void GamePlayPlay::OnEnd()
{
}
