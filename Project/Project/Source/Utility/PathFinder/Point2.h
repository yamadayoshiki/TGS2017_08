#ifndef POINT2_H_
#define POINT2_H_

#include <cmath>

class Point2 {
public:
	// �R���X�g���N�^
	Point2(int x = 0, int y = 0);
	// ���������߂�
	float length() const;
	// ���������߂�
	float distance(const Point2& other) const;
	// �s�X�n���������߂�
	float manhattan_distance(const Point2& other) const;
	// �����Z
	const Point2 operator + (const Point2& other) const;
	// �����Z
	const Point2 operator - (const Point2& other) const;
	// ������
	bool operator == (const Point2& other) const;
	// �������Ȃ�
	bool operator != (const Point2& other) const;

	int		x;	// x���W
	int		y;	// y���W
};

#endif // ! 
