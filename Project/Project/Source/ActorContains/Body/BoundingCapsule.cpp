#include "BoundingCircle.h"
#include "BoundingCapsule.h"
#include "BoundingSegment.h"
#include "BoundingBox.h"
#include "OrientedBoundingBox.h"
#include "Ray.h"

#include "../Collision/Collision.h"

// �R���X�g���N�^
BoundingCapsule::BoundingCapsule(const GSvector2& pos, const GSmatrix4& mat, const float& len, const float& rad) :
	Body(ShapeType::Capsule, pos, mat, rad, len) {
	//mPoints[0] = pos + GSvector2(0, 1) * (len - rad);
	//mPoints[1] = pos - GSvector2(0, 1) * (len - rad);
}

// �Փ˔���
bool BoundingCapsule::isCollide(const IBody & other, HitInfo & hitinfo) const {
	if (!other.enabled() || !enabled())return false;
	
	return other.intersects(*this, hitinfo);
}

// �Փ˔���(��)
bool BoundingCapsule::intersects(const BoundingCircle & other, HitInfo & hitinfo) const {
	return Collision::Sphere_Capsule(other.position(), other.radius(), mPosition, mMatrix, mLength, mRadius);
}

// �Փ˔���(�J�v�Z��)
bool BoundingCapsule::intersects(const BoundingCapsule & other, HitInfo & hitinfo) const {
	return Collision::Capsule_Capsule(mPosition, mMatrix, mLength, mRadius, other.mPosition, other.mMatrix, other.mLength, other.mRadius);
}

// �Փ˔���(����)
bool BoundingCapsule::intersects(const BoundingSegment & other, HitInfo & hitinfo) const {
	return Collision::Capsule_Segment(other.position(), other.matrix(), other.length(), mPosition, mMatrix, mLength, mRadius);
}

// �Փ˔���(AABB)
bool BoundingCapsule::intersects(const BoundingBox & other, HitInfo & hitinfo) const {
	return false;
}

bool BoundingCapsule::intersects(const OrientedBoundingBox & other, HitInfo & hitinfo) const
{
	return false;
}

// �Փ˔���(���C)
bool BoundingCapsule::intersects(const Ray & other, HitInfo & hitinfo) const{
	return false;
}

// Body�̕ϊ�
IBodyPtr BoundingCapsule::transform(const GSmatrix4 & mat) const {
	return std::make_shared<BoundingCapsule>(transform_e(mat));
}

// Body�̕ϊ�
BoundingCapsule BoundingCapsule::transform_e(const GSmatrix4 & mat) const{
	return BoundingCapsule(mPosition + GSvector2(mat.getPosition().x, mat.getPosition().y), mMatrix * mat.getRotateMatrix(), mLength * mat.getScale().y, mRadius * mat.getScale().x);
}

// �}�`�`��
void BoundingCapsule::draw() const{
	//Vector3 p[2];
	//p[0] = mPosition + Vector3::Up * mLength / 2 * mMatrix;
	//p[1] = mPosition + Vector3::Down * mLength / 2 * mMatrix;

	//DrawCapsule3D(Vector3::Vector3ToVECTOR(p[0]), Vector3::Vector3ToVECTOR(p[1]), mRadius, 8, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);
}
