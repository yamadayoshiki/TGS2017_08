#include "PlayerState_Crush.h"

PlayerState_Crush::PlayerState_Crush(GSvector2 & position, GSmatrix4 & matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(position, matrix, player, gameManager)
{
}
//�e��ԓƎ��̏�����
void PlayerState_Crush::unique_init()
{

}
//�X�V����
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
//�Փ˔���
void PlayerState_Crush::collide(const Actor& other)
{
	
}
//�I������
void PlayerState_Crush::end()
{

}
//���͏���
void PlayerState_Crush::input()
{

}