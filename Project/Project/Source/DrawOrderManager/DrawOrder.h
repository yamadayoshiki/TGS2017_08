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

	/* ��O�ɕ`�悳������ */
};
#endif // !DRAWORDER_H_
