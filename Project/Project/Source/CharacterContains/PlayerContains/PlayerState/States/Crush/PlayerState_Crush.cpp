#include "PlayerState_Crush.h"
#include"../../../../../WorldContains/EventMessage/EventMessage.h"

PlayerState_Crush::PlayerState_Crush(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{
}
//�e��ԓƎ��̏�����
void PlayerState_Crush::unique_init()
{
	p_Player->getWorld()->sendMessage(EventMessage::PLAYER_CRUSH);
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

//���b�Z�[�W����
void PlayerState_Crush::handleMessage(EventMessage massege, void* param)
{
	switch (massege)
	{
	case EventMessage::PLAYER_ROUNDSLOST:
		change(PlayerStateName::Close);
		break;
	}
}