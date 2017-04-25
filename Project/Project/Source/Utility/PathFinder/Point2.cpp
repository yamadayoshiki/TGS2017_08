#include "Point2.h"

// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
Point2::Point2(int x, int y) : x(x), y(y) {
}

// ’·‚³‚ğ‹‚ß‚é
float Point2::length() const {
	return std::sqrt((float)(x * x + y * y));
}

// ‹——£‚ğ‹‚ß‚é
float Point2::distance(const Point2 & other) const {
	return (*this - other).length();
}

// sŠX’n‹——£‚ğ‹‚ß‚é
float Point2::manhattan_distance(const Point2 & other) const {
	return (float)(std::abs(x - other.x) + std::abs(y - other.y));
}

// ‘«‚µZ
const Point2 Point2::operator + (const Point2& other) const {
	return Point2(x + other.x, y + other.y);
}

// ˆø‚«Z
const Point2 Point2::operator - (const Point2& other) const {
	return Point2(x - other.x, y - other.y);
}

// “™‚µ‚¢
bool Point2::operator == (const Point2 & other) const {
	return (x == other.x) && (y == other.y);
}

// “™‚µ‚­‚È‚¢
bool Point2::operator != (const Point2 & other) const {
	return !(*this == other);
}
