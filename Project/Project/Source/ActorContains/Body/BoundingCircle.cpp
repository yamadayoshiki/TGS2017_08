#include "BoundingCircle.h"

#include "BoundingCapsule.h"
#include "BoundingSegment.h"
#include "BoundingBox.h"
#include "OrientedBoundingBox.h"
#include "Ray.h"

#include "Collision/Collision.h"

//球の判定を作成する
BoundingCircle::BoundingCircle(const GSvector2& pos, const float& rad) :
	Body(ShapeType::Circle, pos, rad){
}

// 衝突判定
bool BoundingCircle::isCollide(const IBody & other, HitInfo & hitinfo) const {
	// どちらかの判定を行わない場合false
	if (!other.enabled() || !enabled())return false;
	
	return other.intersects(*this, hitinfo);
}

// 衝突判定(球)
bool BoundingCircle::intersects(const BoundingCircle & other, HitInfo & hitinfo) const {
	return Collision::Sphere_Sphere(mTransform.m_Position, mRadius, other.position(), other.mRadius);
}

// 衝突判定(カプセル)
bool BoundingCircle::intersects(const BoundingCapsule & other, HitInfo & hitinfo) const {
	return Collision::Sphere_Capsule(mTransform.m_Position, mRadius, other.position(), GS_MATRIX4_IDENTITY, other.length(), other.radius());
}

// 衝突判定(線分)
bool BoundingCircle::intersects(const BoundingSegment & other, HitInfo & hitinfo) const {
	return Collision::Sphere_Segment(mTransform.m_Position, mRadius, other.position(), GS_MATRIX4_IDENTITY, other.length());
}

// 衝突判定(AABB)
bool BoundingCircle::intersects(const BoundingBox & other, HitInfo & hitinfo) const {
	return false;
}

bool BoundingCircle::intersects(const OrientedBoundingBox & other, HitInfo & hitinfo) const
{
	return false;
}

// 衝突判定(レイ)
bool BoundingCircle::intersects(const Ray & other, HitInfo & hitinfo) const{
	return false;
}

// Bodyの変換
IBodyPtr BoundingCircle::transform(const Transform& transform) const {
	return std::make_shared<BoundingCircle>(transform_e(transform));
}

// Bodyの変換
BoundingCircle BoundingCircle::transform_e(const Transform& transform) const {
	return BoundingCircle(mTransform.m_Position + transform.m_Position, mRadius);
}

// 図形描画
void BoundingCircle::draw() const{
	//DrawSphere3D(Vector3::Vector3ToVECTOR(mCenter), mRadius, 32, GetColor(255, 0, 0), GetColor(125, 125, 125), FALSE);
}

