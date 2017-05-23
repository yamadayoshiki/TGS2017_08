#ifndef FORDIRECTION_H_
#define FORDIRECTION_H_
#include "../TurnDirection/TurnDirection.h"
#include <iostream>
#include <unordered_map>

struct GSvector2;

/*
�S������
size_t(unsigned int)�ɑ�����邽��
ebum class�ł͂Ȃ�enum/0�ȏ�Œ�`
*/
enum FourDirectionName
{
	Up = 0,		//��
	Right,		//�E
	Down,		//��
	Left,		//��

	None,		//�Ȃ�
};

//�S����
struct FourDirection
{
	struct
	{
		FourDirectionName name;
	};

	//�R���X�g���N�^
	explicit FourDirection(const FourDirectionName directionName);
	//�R���X�g���N�^
	explicit FourDirection(const GSvector2& vector);
	//�R���X�g���N�^
	explicit FourDirection(const float angle);
	//�f�t�H���g�R���X�g���N�^
	FourDirection();
	//�w������ɉ�](90�x)
	FourDirection Turn(TurnDirection turnDirection);
	//�w������ɉ�](90�x)
	FourDirection GetTurn(TurnDirection turnDirection) const;
	//���]
	FourDirection TurnOver();
	//���]
	FourDirection GetTurnOver() const;
	//GSvector2�ɒu������
	GSvector2 GetVector2() const;
	//�p�x�ɒu������
	float GetAngle() const;
	//Gsvector2��FourDirectionName�ɕϊ�
	static FourDirection GetVector2ToFourDirection(const GSvector2& vector);

	//��r���Z�q
	bool operator==(const FourDirection& fourDirection) const;
	bool operator!=(const FourDirection& fourDirection) const;
};

//��r���Z�q
inline bool FourDirection::operator==(const FourDirection& fourDirection) const {
	const FourDirection& me = *this;
	return me.name == fourDirection.name;
}

//��r���Z�q
inline bool FourDirection::operator!=(const FourDirection& fourDirection) const {
	return !(this->operator==(fourDirection));
}

//�n�b�V���֐��̓��ꉻ
template<>
struct std::hash<FourDirection> {
	size_t operator()(const FourDirection& key) const
	{
		size_t hash;
		hash = key.name;
		return hash;
	}
};

#endif // !FORDIRECTION_H_