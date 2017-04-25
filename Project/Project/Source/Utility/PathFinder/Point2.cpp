#include "Point2.h"

// �R���X�g���N�^
Point2::Point2(int x, int y) : x(x), y(y) {
}

// ���������߂�
float Point2::length() const {
	return std::sqrt((float)(x * x + y * y));
}

// ���������߂�
float Point2::distance(const Point2 & other) const {
	return (*this - other).length();
}

// �s�X�n���������߂�
float Point2::manhattan_distance(const Point2 & other) const {
	return (float)(std::abs(x - other.x) + std::abs(y - other.y));
}

// �����Z
const Point2 Point2::operator + (const Point2& other) const {
	return Point2(x + other.x, y + other.y);
}

// �����Z
const Point2 Point2::operator - (const Point2& other) const {
	return Point2(x - other.x, y - other.y);
}

// ������
bool Point2::operator == (const Point2 & other) const {
	return (x == other.x) && (y == other.y);
}

// �������Ȃ�
bool Point2::operator != (const Point2 & other) const {
	return !(*this == other);
}
