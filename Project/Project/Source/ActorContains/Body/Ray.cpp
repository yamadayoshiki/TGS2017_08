#include "Ray.h"

// コンストラクタ
Ray::Ray(const GSvector2 & position, const GSvector2 & direction) :
	Body(ShapeType::Ray, position, GS_MATRIX4_IDENTITY, direction){}

// 衝突判定
bool Ray::isCollide(const IBody & other, HitInfo & hitinfo) const{
	return false;
}

// 衝突判定(球)
bool Ray::intersects(const BoundingCircle & other, HitInfo & hitinfo) const{
	return false;
}

// 衝突判定(カプセル)
bool Ray::intersects(const BoundingCapsule & other, HitInfo & hitinfo) const{
	return false;
}

// 衝突判定(線分)
bool Ray::intersects(const BoundingSegment & other, HitInfo & hitinfo) const{
	return false;
}

// 衝突判定(AABB)
bool Ray::intersects(const BoundingBox & other, HitInfo & hitinfo) const{
	return false;
}

bool Ray::intersects(const OrientedBoundingBox & other, HitInfo & hitinfo) const
{
	return false;
}

// 衝突判定(レイ)
bool Ray::intersects(const Ray & other, HitInfo & hitinfo) const{
	return false;
}

// Bodyの変換
IBodyPtr Ray::transform(const Transform& transform) const {
	return std::make_shared<Ray>(transform_e(transform));
}

// Bodyの変換
Ray Ray::transform_e(const Transform& transform) const {
	return Ray(mTransform.m_Position + transform.m_Position, mDirection);
}

// 図形描画
void Ray::draw() const{}
