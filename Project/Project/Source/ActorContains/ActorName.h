#ifndef ACTORNAME_H_
#define ACTORNAME_H_

enum class ActorName
{
	/* �v���C���[�O���[�v */
	Player = 0,			//�v���C���[
	Player_Arm,			//�A�[��
	Player_Manager,			//�A�[��

	/* �G�l�~�[�O���[�v */
	Enemy_01,			//�����狲�߂Ȃ����
	Enemy_02,			//��]���Ȃ���ł��
	Enemy_03,			//�X�g�[�J�[
	Enemy_04,			//���܂ꂽ�瓮�����

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
	BreakWall,
	None,
};

#endif // !ACTORNAME_H_
