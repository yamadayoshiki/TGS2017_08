#ifndef ARRANGEDATA_H_
#define ARRANGEDATA_H_

#include "../Utility/FourDirection/FourDirection.h"

//�z�u�f�[�^
struct ArrangeData
{
	struct
	{
		int actorKey;			//�z�u����A�N�^�[�̃L�[
		FourDirection front;	//�z�u����A�N�^�[�̌���
	};

	//�f�t�H���g�R���X�g���N�^
	ArrangeData() {}

	void SetData(const int index)
	{
		//��1���������f�[�^�ɕϊ�
		front = FourDirection(index % 10);
		//����ȊO���L�[�ɕϊ�
		actorKey = index / 10;
	}
};

#endif // !Arrange
