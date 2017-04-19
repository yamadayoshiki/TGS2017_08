#include "BoundingCircle.h"
#include "BoundingCapsule.h"
#include "BoundingSegment.h"
#include "BoundingBox.h"
#include "OrientedBoundingBox.h"
#include "Ray.h"

#include "../Collision/Collision.h"

// コンストラクタ
BoundingCapsule::BoundingCapsule(const GSvector2& pos, const GSmatrix4& mat, const float& len, const float& rad) :
	Body(ShapeType::Capsule, pos, mat, rad, len) {
	//mPoints[0] = pos + GSvector2(0, 1) * (len - rad);
	//mPoints[1] = pos - GSvector2(0, 1) * (len - rad);
}

// 衝突判定
bool BoundingCapsule::isCollide(const IBody & other, HitInfo & hitinfo) const {
	if (!other.enabled() || !enabled())return false;
	
	return other.intersects(*this, hitinfo);
}

// 衝突判定(球)
bool BoundingCapsule::intersects(const BoundingCircle & other, HitInfo & hitinfo) const {
	return Collision::Sphere_Capsule(other.position(), other.radius(), mPosition, mMatrix, mLength, mRadius);
}

// 衝突判定(カプセル)
bool BoundingCapsule::intersects(const BoundingCapsule & other, HitInfo & hitinfo) const {
	return Collision::Capsule_Capsule(mPosition, mMatrix, mLength, mRadius, other.mPosition, other.mMatrix, other.mLength, other.mRadius);
}

// 衝突判定(線分)
bool BoundingCapsule::intersects(const BoundingSegment & other, HitInfo & hitinfo) const {
	return Collision::Capsule_Segment(other.position(), other.matrix(), other.length(), mPosition, mMatrix, mLength, mRadius);
}

// 衝突判定(AABB)
bool BoundingCapsule::intersects(const BoundingBox & other, HitInfo & hitinfo) const {
	return false;
}

bool BoundingCapsule::intersects(const OrientedBoundingBox & other, HitInfo & hitinfo) const
{
	return false;
}

// 衝突判定(レイ)
bool BoundingCapsule::intersects(const Ray & other, HitInfo & hitinfo) const{
	return false;
}

// Bodyの変換
IBodyPtr BoundingCapsule::transform(const GSmatrix4 & mat) const {
	return std::make_shared<BoundingCapsule>(transform_e(mat));
}

// Bodyの変換
BoundingCapsule BoundingCapsule::transform_e(const GSmatrix4 & mat) const{
	return BoundingCapsule(mPosition + GSvector2(mat.getPosition().x, mat.getPosition().y), mMatrix * mat.getRotateMatrix(), mLength * mat.getScale().y, mRadius * mat.getScale().x);
}

// 図形描画
void BoundingCapsule::draw() const{
	//Vector3 p[2];
	//p[0] = mPosition + Vector3::Up * mLength / 2 * mMatrix;
	//p[1] = mPosition + Vector3::Down * mLength / 2 * mMatrix;

	//DrawCapsule3D(Vector3::Vector3ToVECTOR(p[0]), Vector3::Vector3ToVECTOR(p[1]), mRadius, 8, GetColor(255, 255, 255), GetColor(255, 255, 255), FALSE);
}
