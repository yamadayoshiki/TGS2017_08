#ifndef TARGETPOSITION_H_
#define TARGETPOSITION_H_

#include <vector>
#include <GSvector2.h>
#include "../Utility/FourDirection/FourDirection.h"
#include "../Map/MapPtr.h"
#include "../Map/MapType.h"

//�ڕW�n�_�\����
struct Move
{
	GSvector2 position;			//�ڕW�n�_
	FourDirection direction;	//����
};

//�ڕW�n�_�Ǘ��N���X
class TargetPosition
{
public:
	//�R���X�g���N�^
	TargetPosition(
		const MapPtr& map,
		const TurnDirection turnDirection,
		const MapType type);
	//�f�X�g���N�^
	~TargetPosition();
	//���̖ڕW�n�_�̎擾
	GSvector2 GetNextPos();
	//�Ō�̖ڕW�n�_�̎擾
	GSvector2 GetLastPos();
	//�ڕW�n�_�z��̍ŏ��v�f�̍폜
	void Arrival();
	//�ړI�nList�̃N���A
	void Clear();
	//�w��̉�]�������ɐi�߂�}�X������(���W,�����w��)
	void AlongWall(
		const GSvector2 position,
		const FourDirection fourDirection);
	//�w��̉�]�������ɐi�߂�}�X������(�A��)
	void AlongWall();
	//����
	void Clone(const TargetPosition& other);

private:
	//��]����
	TurnDirection m_TurnDirection;
	//�ڕW�n�_�z��
	std::vector<Move> m_List;
	//�}�b�v�^�C�v
	MapType m_Type;
	//�}�b�v
	MapWPtr p_Map;
};

#endif