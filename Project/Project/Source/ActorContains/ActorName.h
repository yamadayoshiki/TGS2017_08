#ifndef ACTORNAME_H_
#define ACTORNAME_H_

enum class ActorName
{
	None = 0,

	/* UI�O���[�v */
	UI_Manager,
	UI_Selector,
	UI_Button,
	UI_Sprite, 
	UI_Text,

	/* �v���C���[�O���[�v */
	PlayerManager = 90,		//�v���C���[
	Player,					//�v���C���[
	Player_Arm,				//�A�[��

	/* �G�l�~�[�O���[�v */
	EnemyManager = 100,
	Enemy_01,			//�����狲�߂Ȃ����
	Enemy_02,			//��]���Ȃ���ł��
	Enemy_03,			//�X�g�[�J�[
	Enemy_04,			//���܂ꂽ�瓮�����
	Enemy_05,			//����������
	Enemy_06,			//�e�@
	Enemy_07,			//
	Enemy_08,
	Enemy_09,
	Enemy_10,
	BreakWall,
};

#endif // !ACTORNAME_H_