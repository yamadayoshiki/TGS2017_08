#ifndef ENEMYCOMMANDNAME_H_
#define ENEMYCOMMANDNAME_H_

//�G�l�~�[�ɑ΂�����̓R�}���h
enum class EnemyCommandName
{
	Straight,						//���i

	AlongWallMoveClockwise,			//���v���ɕǉ����ړ�
	AlongWallMoveAntiClockwise,		//�����v����ɕǉ����ړ�
	AlongWallMoveShoest,			//�ŒZ���[�g�ŕǉ����ړ�
	AlongWall,						//�ǉ���

	Standby,						//�ҋ@

	ClockwiseRotation90,	//���v����90�x��]
	AntiClockwiseRotation90,//�����v����90�x��]
	ReverseRotation,		//���]

	SpinMove,				//�X�s����Ԃňړ�

	None,					//�����Ȃ�
};

#endif