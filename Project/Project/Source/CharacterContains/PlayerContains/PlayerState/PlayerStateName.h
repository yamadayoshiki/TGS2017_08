#ifndef PLAYER_STATE_NAME_H_
#define PLAYER_STATE_NAME_H_

enum class PlayerStateName
{
	//�ʏ���(�A�[�����J���Ă��Ȃ����)
	Idol,		//�Î~���
	Walk,		//�ړ����(����)
	Run,		//�ړ����(����)
	Open,		//�A�[�����J���Ă���
	Closed,		//�A�[����߂Ă�����
	Rounds,		//�͂���ł�����
	Crush,		//�ׂ����
	Throw,		//��������
	Damage,		//�_���[�W���
	Dead,		//����
				
	//�A�[�����J���Ă�����
	A_Idol,			//�Î~���
	A_Walk,			//�ړ����(����)
	A_Run,			//�ړ����(����)

	None		//�_�~�[
};
#endif // !PLAYER_STATE_NAME

