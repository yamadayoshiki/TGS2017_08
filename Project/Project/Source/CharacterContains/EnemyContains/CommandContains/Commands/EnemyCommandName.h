#ifndef ENEMYCOMMANDNAME_H_
#define ENEMYCOMMANDNAME_H_

//�G�l�~�[�ɑ΂�����̓R�}���h
enum class EnemyCommandName
{
	Stop,					//�~�܂�
	ApproachFixedDistance,	//��苗���܂ŋ߂Â�
	LeaveFixedDistance,	//��苗���ȏ㗣���

	MoveRightTargetPos,		//�E�̖ڕW�n�_�ɓ���
	MoveBaseTargetPos,		//�������n�_�ɓ���
	MoveUpTargetPos,		//��̖ڕW�n�_�ɓ���

	Clockwise_90,			//���v����90�x��]
	ChasePlayer,			//�v���C���[��ǂ�������

	Rush,					//�ˌ�����
	Shot,					//�ˌ�����

	None,					//�����Ȃ�
};

#endif