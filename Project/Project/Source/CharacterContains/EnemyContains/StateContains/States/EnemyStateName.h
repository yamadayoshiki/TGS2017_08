#ifndef ENEMYSTATENAME_H_
#define ENEMYSTATENAME_H_

enum class EnemyStateName
{
	//����
	Idle,				//���̏�Ɏ~�܂�
	Move,				//����
	Caught,				//���܂�Ă���
	Crush,				//�ӂ����
	Dead,				//����
	None,				//�_�~�[

	//�ˌ�
	RushPreliminary,	//�ˌ�����
	Rush,				//�ˌ�

	//�ˌ�
	Shot,				//�ˌ�
};

#endif