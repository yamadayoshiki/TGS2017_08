#include "PlayerState_Crush.h"

PlayerState_Crush::PlayerState_Crush(GSvector2 & position, GSmatrix4 & matrix, IGameManagerPtr gameManager)
	:PlayerState_CrushBase(position,matrix,gameManager)
{
}

void PlayerState_Crush::onUniqueInit(Actor & actor)
{
}

void PlayerState_Crush::onUpdate(Actor & actor, float deltaTime)
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
