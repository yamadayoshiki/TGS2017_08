#include "IsCollide2D.h"
#include <GSvector2.h>
#include <cassert>

//軸平行矩形と軸平行矩形
bool IsCollide2D::AARectangleToAARectangle(const GSvector2 centerPos_1, const float width_1, const float height_1, const GSvector2 centerPos_2, const float width_2, const float height_2) {
	//中心座標同士の距離ベクトル
	GSvector2 dis = centerPos_2 - centerPos_1;

	if (width_1 / 2 + width_2 / 2 < fabs(dis.x))
		return false;

	if (height_1 / 2 + height_2 / 2 < fabs(dis.y))
		return false;

	return true;
}

//軸平行矩形と矩形
bool IsCollide2D::AARectangleToRectangle(const GSvector2 centerPos_1, const float width_1, const float height_1, const GSvector2 centerPos_2, const float width_2, const float height_2, const float angle){
	assert(!"Can't Collide");
	return false;
}

//軸平行矩形と線分
bool IsCollide2D::AARectangleToLine(const GSvector2 centerPos, const float width, const float height, const GSvector2 start, const GSvector2 vector){
	assert(!"Can't Collide");
	return false;
}

//矩形と矩形
bool IsCollide2D::RectangleToRectangle(const GSvector2 centerPos_1, const float width_1, const float height_1, const float angle_1, const GSvector2 centerPos_2, const float width_2, const float height_2, const float angle_2){
	assert(!"Can't Collide");
	return false;
}

//矩形と線分
bool IsCollide2D::RectangleToLine(const GSvector2 centerPos, const float width, const float height, const float angle, const GSvector2 start, const GSvector2 vector){
	assert(!"Can't Collide");
	return false;
}

//線分と線分
bool IsCollide2D::LineToLine(const GSvector2 start_1, const GSvector2 vector_1, const GSvector2 start_2, const GSvector2 vector_2) {
	//始点同士の距離ベクトル
	GSvector2 v = start_2 - start_1;

	//平行か
	float cross_v1Tov2 = vector_1.CCW(vector_2);
	if (fabs(cross_v1Tov2) <= EPSILON)
		return false;

	//始点から交点までの割合
	float t1;
	float t2;

	t1 = v.CCW(vector_2) / vector_1.CCW(vector_2);
	t2 = v.CCW(vector_1) / vector_1.CCW(vector_2);

	if (t1 >= 0.0f && t1 <= 1.0f && t2 >= 0.0f && t2 <= 1.0f)
		return true;

	return false;
}
