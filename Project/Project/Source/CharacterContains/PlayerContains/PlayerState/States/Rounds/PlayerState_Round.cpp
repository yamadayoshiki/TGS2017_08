#include"PlayerState_Round.h"

//�R���X�g���N�^
PlayerState_Round::PlayerState_Round(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Round::unique_init()
{

}
//�X�V����
void PlayerState_Round::update(float deltaTime)
{

}
//�Փ˔���
void PlayerState_Round::collide(const Actor& other)
{
	
}
//�I������
void PlayerState_Round::end()
{

}
//���͏���
void PlayerState_Round::input()
{
	//�ׂ���ԂɑJ��
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_Y)) {
		change(PlayerStateName::Crush);
	}
	//������ԂɑJ��
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_B)) {
		change(PlayerStateName::Release);
	}
}