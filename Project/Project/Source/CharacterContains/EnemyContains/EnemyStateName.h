#ifndef ENEMYSTATENAME_H_
#define ENEMYSTATENAME_H_

enum class EnemyStateName
{
	//����
	Idel,				//���̏�Ɏ~�܂�
	Move,				//����
	Caught,				//���܂�Ă���
	Thrown,				//�������Ă���
	Crush,				//�ӂ����
	Dead,				//����
	None,				//�_�~�[

	//�ˌ��G
	Rush_Preliminary,	//�ˌ�����
	Rush,				//�ˌ�

	//�l���ɒe���o���G
	FourDirectionShot,	//�l���ɒe���o��
};

#endif // !ENEMYSTATENAME_H_