#ifndef ENEMYCOMMANDNAME_H_
#define ENEMYCOMMANDNAME_H_

//�G�l�~�[�ɑ΂�����̓R�}���h
enum class EnemyCommandName
{
	XAxiallyMove,			//X���ړ�
	YAxiallyMove,			//Y���ړ�

	AlongWallMoveClockwise,			//���v���ɕǉ����ړ�
	AlongWallMoveAntiClockwise,		//�����v����ɕǉ����ړ�


	ClockwiseRotation90,	//���v����90�x��]
	AntiClockwiseRotation90,//�����v����90�x��]
	ReverseRotation,		//���]

	None,					//�����Ȃ�
};

#endif