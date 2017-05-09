#include "PlayerState_Crush.h"

PlayerState_Crush::PlayerState_Crush(GSvector2 & position, GSmatrix4 & matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(position, matrix, player, gameManager)
{
}
//各状態独自の初期化
void PlayerState_Crush::unique_init()
{

}
//更新処理
void PlayerState_Crush::update(float deltaTime)
{
	if (p_Input->IsPadState(GS_XBOX_PAD_Y)) {
		m_FrameCounter += deltaTime;
	}

	if (m_FrameCounter < 10 && p_Input->IsPadStatesDetach(GS_XBOX_PAD_Y)) {
		change(PlayerStateName::Crush_Barrage);
		m_FrameCounter = 0;
	}
	else if (m_FrameCounter > 10) {
		change(PlayerStateName::Crush_Hold);
		m_FrameCounter = 0;
	}
}
//衝突判定
void PlayerState_Crush::collide(const Actor& other)
{
	
}
//終了処理
void PlayerState_Crush::end()
{

}
//入力処理
void PlayerState_Crush::input()
{

}