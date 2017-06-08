#ifndef PLAYER_STATE_NAME_H_
#define PLAYER_STATE_NAME_H_

enum class PlayerStateName
{
	//�ʏ���(�A�[�����J���Ă��Ȃ����)
	Idle,				//�Î~���
	Walk,				//�ړ����(����)
	Dash,				//
	Close,				//�A�[����߂Ă�����
				
	//�A�[�����J���Ă�����
	Open,				//�A�[�����J���Ă���
	O_Idle,				//�Î~���
	O_Walk,				//�ړ����(����)

	//��������ł�����
	Rounds,			//�͂���ł�����

	//�ׂ����
	Crush,			//�ׂ����
	Crush_After,	//�ׂ�����̏��

	//����
	Damage,			//�_���[�W���
	Release,		//�������
	Invincible,		//���G���
	Swich,			//�؂�ւ�
	Dead,			//����
	None			//�_�~�[
};
#endif // !PLAYER_STATE_NAME

