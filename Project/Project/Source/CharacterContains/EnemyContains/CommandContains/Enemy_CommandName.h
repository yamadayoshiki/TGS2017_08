#ifndef ENEMY_COMMANDNAME_H_
#define ENEMY_COMMANDNAME_H_

//�G�l�~�[�ɑ΂�����̓R�}���h
enum class Enemy_CommandName
{
	//�ړ�
	Idle,					//�~�܂�
	Approach_FixedDistance,	//��苗���܂ŋ߂Â�
	Leave_FixedDistance,	//��苗���ȏ㗣���

	//�U��
	Rush,					//�ˌ�����
	Shot,					//�ˌ�����
};

#endif // !ENEMY_COMMANDNAME_H_
