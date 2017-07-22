#ifndef ISCOLLIDE2D_H_
#define ISCOLLIDE2D_H_
struct GSvector2;
namespace Body {
	struct Contact;
	struct AABB2D;
	struct AASegment2D;
}
//�Փ˔���v�Z����
namespace IsCollide2D
{
	//���������_�덷
	static float EPSILON = 0.000001f;

	//AABB��AABB
	Body::Contact AABB2DToAABB2D(
		const Body::AABB2D AABB2D_1,
		const Body::AABB2D AABB2D_2);

	//AABB��AASegment
	Body::Contact AABB2DToAASegment2D(
		const Body::AABB2D AABB2D,
		const Body::AASegment2D AASegment2D);

	////�����s��`�Ǝ����s��`
	//bool AARectangleToAARectangle(
	//	const GSvector2 centerPos_1, const float width_1, const float height_1,
	//	const GSvector2 centerPos_2, const float width_2, const float height_2);

	////�����s��`�Ƌ�`
	//bool AARectangleToRectangle(
	//	const GSvector2 centerPos_1, const float width_1, const float height_1,
	//	const GSvector2 centerPos_2, const float width_2, const float height_2, const float angle);

	////�����s��`�Ɛ���
	//bool AARectangleToLine(
	//	const GSvector2 centerPos, const float width, const float height,
	//	const GSvector2 start, const GSvector2 vector);

	////��`�Ƌ�`
	//bool RectangleToRectangle(
	//	const GSvector2 centerPos_1, const float width_1, const float height_1, const float angle_1,
	//	const GSvector2 centerPos_2, const float width_2, const float height_2, const float angle_2);

	////��`�Ɛ���
	//bool RectangleToLine(
	//	const GSvector2 centerPos, const float width, const float height, const float angle,
	//	const GSvector2 start, const GSvector2 vector);

	////�����Ɛ���
	//bool LineToLine(
	//	const GSvector2 start_1, const GSvector2 vector_1,
	//	const GSvector2 start_2, const GSvector2 vector_2);
}
#endif