#ifndef SOUNDNAME_H_
#define SOUNDNAME_H_


enum SoundName
{

	//PlayerSE
	SE_PLAYER_ARM = 0,			//�A�[���J��
	SE_PLAYER_CLIP,				//���񂾎�
	SE_PLAYER_DASH,				//�_�b�V��
	SE_PLAYER_CRUSH,			//�ׂ��Ă���Ƃ�
	SE_PLAYER_CRUSH_AFTER,		//�ׂ����Ƃ�
	SE_PLAYER_EXPLOSION,		//���@�̔���
	SE_PLAYER_PLAY,				//�e�����Ƃ�
	SE_PLAYER_RESPAWN,			//���X�|�[��

	//EnemySE
	SE_ENEMY_CHILDAPPEARED,		//�q�@�o��
	SE_ENEMY_ENEMYEXPLOTION,	//�G����
	SE_ENEMY_GENERATESINGING,	//�e�@�����r��
	SE_ENEMY_RUSH,				//�ːi
	SE_ENEMY_SHOT,				//�ˌ�
	SE_ENEMY_SPINBOUND,			//�ǂ��璵�˕Ԃ�

	//BGM
	BGM_GAME_TITLE,				//�^�C�g��BGM
	BGM_GAME_PLAY,				//�Q�[��PlayBGM
	BGM_GAME_CLER,				//�Q�[���N���ABGM
	BGM_GAME_OVER,				//�Q�[���I�[�o�[BGM
};

#endif