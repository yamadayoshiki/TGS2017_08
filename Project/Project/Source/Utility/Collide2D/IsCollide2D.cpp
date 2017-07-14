#include "IsCollide2D.h"
#include <GSvector2.h>
#include <cassert>
#include "../Contact/Contact.h"
#include "../../ActorContains/BodyContains/Elements/Primitive/AABB2D/AABB2D.h"
#include "../../ActorContains/BodyContains/Elements/Primitive/AASegment2D/AASegment2D.h"

Body::Contact IsCollide2D::AABB2DToAABB2D(const Body::AABB2D AABB2D_1, const Body::AABB2D AABB2D_2) {
	//���ʕϐ�
	Body::Contact result;

	//���S���W���m�̋����x�N�g��
	GSvector2 dis = AABB2D_2.centerPoint - AABB2D_1.centerPoint;

	//�ђʐ[�x
	float penetrateDis_x = (AABB2D_1.LengthX() / 2 + AABB2D_2.LengthX() / 2) - fabs(dis.x);
	float penetrateDis_y = (AABB2D_1.LengthY() / 2 + AABB2D_2.LengthY() / 2) - fabs(dis.y);

	//�Փ˂��Ă��Ȃ�
	if (penetrateDis_x < 0 || penetrateDis_y < 0)
		return result;

	//�Փ˂��Ă���
	else
	{
		//�Փ˓_
		ContactPoint cp;
		//�󂢂ق����Փ˓_�Ƃ���
		cp.distance = penetrateDis_x;
		cp.normal = { dis.x / fabs(dis.x), 0 };
		if (cp.distance > penetrateDis_y)
		{
			cp.distance = penetrateDis_y;
			cp.normal = { 0,dis.y / fabs(dis.y) };
		}
		result.Add(cp);
		return result;
	}
}

Body::Contact IsCollide2D::AABB2DToAASegment2D(
	const Body::AABB2D AABB2D,
	const Body::AASegment2D AASegment2D) {
	//���ʕϐ�
	Body::Contact result;

	//���S���W���m�̋����x�N�g��
	GSvector2 dis = (AASegment2D.point + (AASegment2D.vector / 2)) - AABB2D.centerPoint;

	//�ђʐ[�x
	float penetrateDis_x = (AABB2D.LengthX() / 2 + AASegment2D.LengthX() / 2) - fabs(dis.x);
	float penetrateDis_y = (AABB2D.LengthY() / 2 + AASegment2D.LengthY() / 2) - fabs(dis.y);

	//�Փ˂��Ă��Ȃ�
	if (penetrateDis_x < 0 || penetrateDis_y < 0)
		return result;

	//�Փ˂��Ă���
	else
	{
		//�Փ˓_
		ContactPoint cp;
		//�󂢂ق����Փ˓_�Ƃ���
		cp.distance = penetrateDis_x;
		cp.normal = { dis.x / fabs(dis.x), 0 };
		if (cp.distance > penetrateDis_y)
		{
			cp.distance = penetrateDis_y;
			cp.normal = { 0,dis.y / fabs(dis.y) };
		}
		result.Add(cp);
		return result;
	}
}

////�����s��`�Ƌ�`
//bool IsCollide2D::AARectangleToRectangle(const GSvector2 centerPos_1, const float width_1, const float height_1, const GSvector2 centerPos_2, const float width_2, const float height_2, const float angle){
//	assert(!"Can't Collide");
//	return false;
//}
//
////�����s��`�Ɛ���
//bool IsCollide2D::AARectangleToLine(const GSvector2 centerPos, const float width, const float height, const GSvector2 start, const GSvector2 vector){
//	assert(!"Can't Collide");
//	return false;
//}
//
////��`�Ƌ�`
//bool IsCollide2D::RectangleToRectangle(const GSvector2 centerPos_1, const float width_1, const float height_1, const float angle_1, const GSvector2 centerPos_2, const float width_2, const float height_2, const float angle_2){
//	assert(!"Can't Collide");
//	return false;
//}
//
////��`�Ɛ���
//bool IsCollide2D::RectangleToLine(const GSvector2 centerPos, const float width, const float height, const float angle, const GSvector2 start, const GSvector2 vector){
//	assert(!"Can't Collide");
//	return false;
//}
//
////�����Ɛ���
//bool IsCollide2D::LineToLine(const GSvector2 start_1, const GSvector2 vector_1, const GSvector2 start_2, const GSvector2 vector_2) {
//	//�n�_���m�̋����x�N�g��
//	GSvector2 v = start_2 - start_1;
//
//	//���s��
//	float cross_v1Tov2 = vector_1.CCW(vector_2);
//	if (fabs(cross_v1Tov2) <= EPSILON)
//		return false;
//
//	//�n�_�����_�܂ł̊���
//	float t1;
//	float t2;
//
//	t1 = v.CCW(vector_2) / vector_1.CCW(vector_2);
//	t2 = v.CCW(vector_1) / vector_1.CCW(vector_2);
//
//	if (t1 >= 0.0f && t1 <= 1.0f && t2 >= 0.0f && t2 <= 1.0f)
//		return true;
//
//	return false;
//}
