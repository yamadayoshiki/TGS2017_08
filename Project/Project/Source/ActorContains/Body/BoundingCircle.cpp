#include "BoundingCircle.h"

#include "BoundingCapsule.h"
#include "BoundingSegment.h"
#include "BoundingBox.h"
#include "OrientedBoundingBox.h"
#include "Ray.h"

#include "Collision/Collision.h"

//���̔�����쐬����
BoundingCircle::BoundingCircle(const GSvector2& pos, const float& rad) :
	Body(ShapeType::Circle, pos, rad){
}

// �Փ˔���
bool BoundingCircle::isCollide(const IBody & other, HitInfo & hitinfo) const {
	// �ǂ��炩�̔�����s��Ȃ��ꍇfalse
	if (!other.enabled() || !enabled())return false;
	
	return other.intersects(*this, hitinfo);
}

// �Փ˔���(��)
bool BoundingCircle::intersects(const BoundingCircle & other, HitInfo & hitinfo) const {
	return Collision::Sphere_Sphere(mTransform.m_Position, mRadius, other.position(), other.mRadius);
}

// �Փ˔���(�J�v�Z��)
bool BoundingCircle::intersects(const BoundingCapsule & other, HitInfo & hitinfo) const {
	return Collision::Sphere_Capsule(mTransform.m_Position, mRadius, other.position(), GS_MATRIX4_IDENTITY, other.length(), other.radius());
}

// �Փ˔���(����)
bool BoundingCircle::intersects(const BoundingSegment & other, HitInfo & hitinfo) const {
	return Collision::Sphere_Segment(mTransform.m_Position, mRadius, other.position(), GS_MATRIX4_IDENTITY, other.length());
}

// �Փ˔���(AABB)
bool BoundingCircle::intersects(const BoundingBox & other, HitInfo & hitinfo) const {
	return false;
}

bool BoundingCircle::intersects(const OrientedBoundingBox & other, HitInfo & hitinfo) const
{
	return false;
}

// �Փ˔���(���C)
bool BoundingCircle::intersects(const Ray & other, HitInfo & hitinfo) const{
	return false;
}

// Body�̕ϊ�
IBodyPtr BoundingCircle::transform(const Transform& transform) const {
	return std::make_shared<BoundingCircle>(transform_e(transform));
}

// Body�̕ϊ�
BoundingCircle BoundingCircle::transform_e(const Transform& transform) const {
	return BoundingCircle(mTransform.m_Position + transform.m_Position, mRadius);
}

// �}�`�`��
void BoundingCircle::draw() const{
	//DrawSphere3D(Vector3::Vector3ToVECTOR(mCenter), mRadius, 32, GetColor(255, 0, 0), GetColor(125, 125, 125), FALSE);
}

