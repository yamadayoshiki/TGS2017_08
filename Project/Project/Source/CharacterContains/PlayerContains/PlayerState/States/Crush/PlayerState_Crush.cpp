#include "PlayerState_Crush.h"

PlayerState_Crush::PlayerState_Crush(GSvector2 & position, GSmatrix4 & matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_CrushBase(position, matrix, player, gameManager)
{
}

void PlayerState_Crush::onUniqueInit()
{
}

void PlayerState_Crush::onUpdate(float deltaTime)
{
	if (p_Input->IsPadState(GS_XBOX_PAD_B)) {
		m_FrameCounter += deltaTime;
	}

	if (m_FrameCounter < 10) {
		change(PlayerStateName::Crush_Barrage);
	}
	else {
		change(PlayerStateName::Crush_Hold);
	}
}
