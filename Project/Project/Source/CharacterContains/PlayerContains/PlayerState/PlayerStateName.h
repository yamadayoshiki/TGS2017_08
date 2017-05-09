#ifndef PLAYER_STATE_NAME_H_
#define PLAYER_STATE_NAME_H_

enum class PlayerStateName
{
	//�ʏ���(�A�[�����J���Ă��Ȃ����)
	Idle,				//�Î~���
	Walk,				//�ړ����(����)
	Run,				//�ړ����(����)
	Dash,				//
	Close,				//�A�[����߂Ă�����
				
	//�A�[�����J���Ă�����
	Open,				//�A�[�����J���Ă���
	O_Idle,				//�Î~���
	O_Walk,				//�ړ����(����)
	O_Run,				//�ړ����(����)

	//��������ł�����
	Rounds,			//�͂���ł�����
	R_Idle,			//�Î~���
	R_Walk,			//�ړ����(����)
	R_Run,			//�ړ����(����)

	//�ׂ����
	Crush,			//�ׂ����
	Crush_Barrage,	//�ׂ����(�A��)
	Crush_Hold,		//�ׂ����(������)

	//����
	Damage,			//�_���[�W���
	Release,		//�������
	Swich,			//�؂�ւ�
	Dead,			//����
	None			//�_�~�[
};
#endif // !PLAYER_STATE_NAME

