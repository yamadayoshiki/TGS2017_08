#include "Ray.h"

// �R���X�g���N�^
Ray::Ray(const GSvector2 & position, const GSvector2 & direction) :
	Body(ShapeType::Ray, position, GS_MATRIX4_IDENTITY, direction){}

// �Փ˔���
bool Ray::isCollide(const IBody & other, HitInfo & hitinfo) const{
	return false;
}

// �Փ˔���(��)
bool Ray::intersects(const BoundingCircle & other, HitInfo & hitinfo) const{
	return false;
}

// �Փ˔���(�J�v�Z��)
bool Ray::intersects(const BoundingCapsule & other, HitInfo & hitinfo) const{
	return false;
}

// �Փ˔���(����)
bool Ray::intersects(const BoundingSegment & other, HitInfo & hitinfo) const{
	return false;
}

// �Փ˔���(AABB)
bool Ray::intersects(const BoundingBox & other, HitInfo & hitinfo) const{
	return false;
}

bool Ray::intersects(const OrientedBoundingBox & other, HitInfo & hitinfo) const
{
	return false;
}

// �Փ˔���(���C)
bool Ray::intersects(const Ray & other, HitInfo & hitinfo) const{
	return false;
}

// Body�̕ϊ�
IBodyPtr Ray::transform(const Transform& transform) const {
	return std::make_shared<Ray>(transform_e(transform));
}

// Body�̕ϊ�
Ray Ray::transform_e(const Transform& transform) const {
	return Ray(mTransform.m_Position + transform.m_Position, mDirection);
}

// �}�`�`��
void Ray::draw() const{}
