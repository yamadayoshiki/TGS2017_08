#ifndef ISCOLLIDE2D_H_
#define ISCOLLIDE2D_H_
struct GSvector2;
namespace Body {
	struct Contact;
	struct AABB2D;
	struct AASegment2D;
}
//衝突判定計算処理
namespace IsCollide2D
{
	//浮動小数点誤差
	static float EPSILON = 0.000001f;

	//AABBとAABB
	Body::Contact AABB2DToAABB2D(
		const Body::AABB2D AABB2D_1,
		const Body::AABB2D AABB2D_2);

	//AABBとAASegment
	Body::Contact AABB2DToAASegment2D(
		const Body::AABB2D AABB2D,
		const Body::AASegment2D AASegment2D);

	////軸平行矩形と軸平行矩形
	//bool AARectangleToAARectangle(
	//	const GSvector2 centerPos_1, const float width_1, const float height_1,
	//	const GSvector2 centerPos_2, const float width_2, const float height_2);

	////軸平行矩形と矩形
	//bool AARectangleToRectangle(
	//	const GSvector2 centerPos_1, const float width_1, const float height_1,
	//	const GSvector2 centerPos_2, const float width_2, const float height_2, const float angle);

	////軸平行矩形と線分
	//bool AARectangleToLine(
	//	const GSvector2 centerPos, const float width, const float height,
	//	const GSvector2 start, const GSvector2 vector);

	////矩形と矩形
	//bool RectangleToRectangle(
	//	const GSvector2 centerPos_1, const float width_1, const float height_1, const float angle_1,
	//	const GSvector2 centerPos_2, const float width_2, const float height_2, const float angle_2);

	////矩形と線分
	//bool RectangleToLine(
	//	const GSvector2 centerPos, const float width, const float height, const float angle,
	//	const GSvector2 start, const GSvector2 vector);

	////線分と線分
	//bool LineToLine(
	//	const GSvector2 start_1, const GSvector2 vector_1,
	//	const GSvector2 start_2, const GSvector2 vector_2);
}
#endif