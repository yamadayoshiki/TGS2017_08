#ifndef POINT2_H_
#define POINT2_H_

#include <cmath>

class Point2 {
public:
	// コンストラクタ
	Point2(int x = 0, int y = 0);
	// 長さを求める
	float length() const;
	// 距離を求める
	float distance(const Point2& other) const;
	// 市街地距離を求める
	float manhattan_distance(const Point2& other) const;
	// 足し算
	const Point2 operator + (const Point2& other) const;
	// 引き算
	const Point2 operator - (const Point2& other) const;
	// 等しい
	bool operator == (const Point2& other) const;
	// 等しくない
	bool operator != (const Point2& other) const;

	int		x;	// x座標
	int		y;	// y座標
};

#endif // ! 
