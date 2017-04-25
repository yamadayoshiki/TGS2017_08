#include "Point2.h"

// コンストラクタ
Point2::Point2(int x, int y) : x(x), y(y) {
}

// 長さを求める
float Point2::length() const {
	return std::sqrt((float)(x * x + y * y));
}

// 距離を求める
float Point2::distance(const Point2 & other) const {
	return (*this - other).length();
}

// 市街地距離を求める
float Point2::manhattan_distance(const Point2 & other) const {
	return (float)(std::abs(x - other.x) + std::abs(y - other.y));
}

// 足し算
const Point2 Point2::operator + (const Point2& other) const {
	return Point2(x + other.x, y + other.y);
}

// 引き算
const Point2 Point2::operator - (const Point2& other) const {
	return Point2(x - other.x, y - other.y);
}

// 等しい
bool Point2::operator == (const Point2 & other) const {
	return (x == other.x) && (y == other.y);
}

// 等しくない
bool Point2::operator != (const Point2 & other) const {
	return !(*this == other);
}
