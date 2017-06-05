#ifndef ACTORNAME_H_
#define ACTORNAME_H_

enum class ActorName
{
	/* �v���C���[�O���[�v */
	Player = 0,			//�v���C���[
	Player_Arm,			//�A�[��
	Player_Manager,			//�A�[��



	/* �j���[�g�����O���[�v */
	Neutral_Explosion,	//����

	/* UI�O���[�v */
	UI_Manager,
	UI_Selector,
	UI_Button,
	UI_Sprite, 
	UI_Text,

	/* �e�X�g�p */
	EnemyManager,
	Enemy,

	/* �G�l�~�[�O���[�v */
	Enemy_01 = 101,		//�����狲�߂Ȃ����
	Enemy_02,			//��]���Ȃ���ł��
	Enemy_03,			//�X�g�[�J�[
	Enemy_04,			//���܂ꂽ�瓮�����
	Enemy_05,			//����������
	Enemy_06,			//�e�@
	Enemy_07,			//
	BreakWall,

	None,
};

#endif // !ACTORNAME_H_
