#ifndef ENEMY_COMMANDNAME_H_
#define ENEMY_COMMANDNAME_H_

//�G�l�~�[�ɑ΂�����̓R�}���h
enum class Enemy_CommandName
{
	//�ړ�
	Idle,					//�~�܂�
	Approach_FixedDistance,	//��苗���܂ŋ߂Â�
	Leave_FixedDistance,	//��苗���ȏ㗣���
	Translation,			//���s�ړ�
	Rotation,				//��]
	Chase,					//�ǂ�������

	//�U��
	Rush,					//�ˌ�����
	Shot,					//�ˌ�����
};

#endif // !ENEMY_COMMANDNAME_H_
