#ifndef PLAYER_STATE_NAME_H_
#define PLAYER_STATE_NAME_H_

enum class PlayerStateName
{
	//�ʏ���(�A�[�����J���Ă��Ȃ����)
	Idol,		//�Î~���
	Walk,		//�ړ����(����)
	Run,		//�ړ����(����)
	Closed,		//�A�[����߂Ă�����
				
	//�A�[�����J���Ă�����
	Open,		//�A�[�����J���Ă���
	O_Idol,			//�Î~���
	O_Walk,			//�ړ����(����)
	O_Run,			//�ړ����(����)

	//��������ł�����
	Rounds,		//�͂���ł�����
	R_Idol,		//�Î~���
	R_Walk,		//�ړ����(����)
	R_Run,		//�ړ����(����)
	Crush,		//�ׂ����
	Throw,		//��������

	//����
	Damage,		//�_���[�W���
	Dead,		//����
	None		//�_�~�[
};
#endif // !PLAYER_STATE_NAME

