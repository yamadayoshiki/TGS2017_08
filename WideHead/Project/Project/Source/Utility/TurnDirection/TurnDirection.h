#ifndef TURNDIRECTION_H_
#define TURNDIRECTION_H_

//��]�������O
enum class TurnDirectionName
{
	Clockwise,		//���v���
	AntiClockwise,	//�����v���

	None,			//�Ȃ�
};

//��]����
struct TurnDirection
{
	struct
	{
		TurnDirectionName name;
	};

	//�R���X�g���N�^
	TurnDirection(TurnDirectionName name);
	//�f�t�H���g�R���X�g���N�^
	TurnDirection();
	//���]
	TurnDirection Reversal();
	//���]
	TurnDirection GetReversal();
};

#endif