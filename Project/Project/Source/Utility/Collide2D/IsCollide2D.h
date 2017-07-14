#ifndef ISCOLLIDE2D_H_
#define ISCOLLIDE2D_H_
struct GSvector2;
namespace Body {
	struct Contact;
	struct AABB2D;
	struct AASegment2D;
}
//ÕË»èvZ
namespace IsCollide2D
{
	//®¬_ë·
	static float EPSILON = 0.000001f;

	//AABBÆAABB
	Body::Contact AABB2DToAABB2D(
		const Body::AABB2D AABB2D_1,
		const Body::AABB2D AABB2D_2);

	//AABBÆAASegment
	Body::Contact AABB2DToAASegment2D(
		const Body::AABB2D AABB2D,
		const Body::AASegment2D AASegment2D);

	////²½sé`Æ²½sé`
	//bool AARectangleToAARectangle(
	//	const GSvector2 centerPos_1, const float width_1, const float height_1,
	//	const GSvector2 centerPos_2, const float width_2, const float height_2);

	////²½sé`Æé`
	//bool AARectangleToRectangle(
	//	const GSvector2 centerPos_1, const float width_1, const float height_1,
	//	const GSvector2 centerPos_2, const float width_2, const float height_2, const float angle);

	////²½sé`Æüª
	//bool AARectangleToLine(
	//	const GSvector2 centerPos, const float width, const float height,
	//	const GSvector2 start, const GSvector2 vector);

	////é`Æé`
	//bool RectangleToRectangle(
	//	const GSvector2 centerPos_1, const float width_1, const float height_1, const float angle_1,
	//	const GSvector2 centerPos_2, const float width_2, const float height_2, const float angle_2);

	////é`Æüª
	//bool RectangleToLine(
	//	const GSvector2 centerPos, const float width, const float height, const float angle,
	//	const GSvector2 start, const GSvector2 vector);

	////üªÆüª
	//bool LineToLine(
	//	const GSvector2 start_1, const GSvector2 vector_1,
	//	const GSvector2 start_2, const GSvector2 vector_2);
}
#endif