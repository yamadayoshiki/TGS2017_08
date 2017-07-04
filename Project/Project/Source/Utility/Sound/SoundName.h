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
	SE_PLAYER_CHARGE_FRIST,		//�`���[�W1�i�K��
	SE_PLAYER_CHARGE_SECOND,	//�`���[�W2�i�K��
	SE_PLAYER_CHARGE_THIRD,		//�`���[�W3�i�K��

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

	//TutorialSE
	SE_GAID,					//�`���[�g���A���K�C�hSE

	//TitleSE
	SE_TITLE_DOWN,				//�^�C�g�����S�̍~��SE

	//PlaySE
	SE_WHISTL,					//�X�^�[�g�A�G���h��SE
	SE_PLAY_FONT,				//�t�H���g�̕\��SE
	SE_STAGE_CLER,				//�X�e�[�W�N���ASE

	//ResultSE
	SE_S,						//�����NSSE
	SE_A,						//�����NASE
	SE_B,						//�����NBSE
	SE_C,						//�����NCSE
	SE_SCORE_ROLE,				//�X�R�A���[��SE
	SE_BLOCK_BREAK,				//�u���b�N�j��SE

	//SE
	SE_BACK,					//�߂�
	SE_DECITION,				//����
	SE_KOMBOUP,					//�R���{�A�b�v
	SE_PAUSE_CLOSE,				//�|�[�Y�����
	SE_PAUSE_OPEN,				//�|�[�Y���J��
	SE_SHOWINGSCORE,			//�X�R�A�\��
	SE_SHOWINGSCORE_BEFORE,		//�X�R�A�\���O
	SE_START,					//�X�^�[�g
};

#endif