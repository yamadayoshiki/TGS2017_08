#ifndef DRAWORDER_H_
#define DRAWORDER_H_
//�`�揇��
enum class DrawOrder
{
	/* ���ɕ`�悳������ */

	BackGround=0,		//�w�i
	Map,				//�n�`
	
	Effect_Back,		//�����o

	/*�L����*/
	Enemy,
	Player,

	Effect_Front,		//��O���o

	/*UI*/
	UI,
	UI_Front1,
	UI_Front2,
	UI_Front3,

	/*�|�[�Y���j���[*/
	PauseBack,
	PauseUI,

	BlackScreen,
	/* ��O�ɕ`�悳������ */
};
#endif // !DRAWORDER_H_
