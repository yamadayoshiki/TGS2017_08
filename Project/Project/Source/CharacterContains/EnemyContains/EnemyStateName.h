#ifndef ENEMYSTATENAME_H_
#define ENEMYSTATENAME_H_

enum class EnemyStateName
{
	//����
	Idle,				//���̏�Ɏ~�܂�
	Move,				//����
	Caught,				//���܂�Ă���
	Thrown,				//�������Ă���
	Crush,				//�ӂ����
	Dead,				//����
	None,				//�_�~�[

	//�ˌ��G
	Rush_Preliminary,	//�ˌ�����
	Rush,				//�ˌ�

	//�ˌ�
	Shot,				//�ˌ�
};

#endif // !ENEMYSTATENAME_H_