#ifndef ENEMYSTATENAME_H_
#define ENEMYSTATENAME_H_

enum class EnemyStateName
{
	//����
	Idle,				//���̏�Ɏ~�܂�
	Move,				//����
	Caught,				//���܂�Ă���
	Crush,				//�ӂ����
	Repel,				//�e��
	Dead,				//����
	None,				//�_�~�[
	Stop,				//�~�܂�

	//�ˌ�
	RushPreliminary,	//�ˌ�����
	Rush,				//�ˌ�

	//�ˌ�
	Shot,				//�ˌ�
};

#endif