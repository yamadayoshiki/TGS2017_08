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
	Damage,				//�_���[�W���󂯂Ă���

	//�ˌ�
	RushPreliminary,	//�ˌ�����
	Rush,				//�ˌ�
	StickWall,			//�ǂɎh�����Ă���

	//�m�R�m�R�X�s��
	Spin,

	//�ˌ�
	Shot,				//�ˌ�
};

#endif