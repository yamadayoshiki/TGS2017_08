#include "BoundingCircle.h"

#include "BoundingCapsule.h"
#include "BoundingSegment.h"
#include "BoundingBox.h"
#include "OrientedBoundingBox.h"
#include "Ray.h"

#include "Collision/Collision.h"

// �R���X�g���N�^
BoundingSegment::BoundingSegment(const GSvector2 & pos, const GSmatrix4 & mat, const float& len) :
	Body(ShapeType::Segment, pos, mat, len, true) {
	mPoints[0] = pos + GSvector2(0, 1) * len / 2;
	mPoints[1] = pos - GSvector2(0, 1) * len / 2;
}

// �Փ˔���
bool BoundingSegment::isCollide(const IBody & other, HitInfo & hitinfo) const {
	// �ǂ��炩�̔�����s��Ȃ��ꍇfalse
	if (!other.enabled() || !enabled())return false;

	return other.intersects(*this, hitinfo);
}

// �Փ˔���(��)
bool BoundingSegment::intersects(const BoundingCircle & other, HitInfo & hitinfo) const {
	return Collision::Sphere_Segment(other.position(), other.radius(), mPosition, mMatrix, mLength);
}

// �Փ˔���(�J�v�Z��)
bool BoundingSegment::intersects(const BoundingCapsule & other, HitInfo & hitinfo) const {
	return Collision::Capsule_Segment(mPosition, mMatrix, mLength, other.position(), other.matrix(), other.length(), other.radius());
}

// �Փ˔���(����)
bool BoundingSegment::intersects(const BoundingSegment & other, HitInfo & hitinfo) const {
	return false;// Collision::Segment_Segment(mPosition, mMatrix, mLength, other.mPosition, other.matrix(), other.length());
}

// �Փ˔���(AABB)
bool BoundingSegment::intersects(const BoundingBox & other, HitInfo & hitinfo) const {
	return false;
}

bool BoundingSegment::intersects(const OrientedBoundingBox & other, HitInfo & hitinfo) const
{
	return false;
}

// �Փ˔���(���C)
bool BoundingSegment::intersects(const Ray & other, HitInfo & hitinfo) const {
	return false;
}

// Body�̕ϊ�
IBodyPtr BoundingSegment::transform(const GSmatrix4 & mat) const {
	return std::make_shared<BoundingSegment>(transform_e(mat));
}

// Body�̕ϊ�
BoundingSegment BoundingSegment::transform_e(const GSmatrix4 & mat) const {
	return BoundingSegment(mPosition + GSvector2(mat.getPosition()), mat, mLength * mat.getScale().y);
}

// �n�_����I�_�ւ̕�����Ԃ�
GSvector2 BoundingSegment::Direction() const {
	//Vector3 p[2];
	//p[0] = mPosition + Vector3::Up * mLength / 2 * mMatrix;
	//p[1] = mPosition + Vector3::Down * mLength / 2 * mMatrix;

	//return Vector3::Normalize(p[0] - p[1]);
	return GSvector2();
}

// ���_
GSvector2 BoundingSegment::Point(int index) const {
	switch (index) {
	default:
	case 0: return mPosition + mLength * GSvector2(0.5f, 0.0f) * mMatrix.getRotateMatrix();
	case 1: return mPosition - mLength * GSvector2(0.5f, 0.0f) * mMatrix.getRotateMatrix();
	}
}

// �}�`�`��
void BoundingSegment::draw() const {
	//Vector3 p[2];
	//p[0] = mPosition + Vector3::Up * mLength / 2 * mMatrix;
	//p[1] = mPosition + Vector3::Down * mLength / 2 * mMatrix;

	//DrawLine3D(Vector3::Vector3ToVECTOR(p[0]), Vector3::Vector3ToVECTOR(p[1]), GetColor(255, 255, 255));
}

