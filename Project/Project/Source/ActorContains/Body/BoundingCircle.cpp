#include "BoundingCircle.h"
#include "BoundingCapsule.h"
#include "BoundingSegment.h"
#include "BoundingBox.h"
#include "Ray.h"

#include "../Collision/Collision.h"

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
	return Collision::Sphere_Sphere(mPosition, mRadius, other.mPosition, other.mRadius);
}

// 衝突判定(カプセル)
bool BoundingCircle::intersects(const BoundingCapsule & other, HitInfo & hitinfo) const {
	return Collision::Sphere_Capsule(mPosition, mRadius, other.position(), other.matrix(), other.length(), other.radius());
}

// 衝突判定(線分)
bool BoundingCircle::intersects(const BoundingSegment & other, HitInfo & hitinfo) const {
	return Collision::Sphere_Segment(mPosition, mRadius, other.position(), other.matrix(), other.length());
}

// 衝突判定(AABB)
bool BoundingCircle::intersects(const BoundingBox & other, HitInfo & hitinfo) const {
	return false;
}

// 衝突判定(レイ)
bool BoundingCircle::intersects(const Ray & other, HitInfo & hitinfo) const{
	return false;
}

// Bodyの平行移動
IBodyPtr BoundingCircle::translate(const GSvector2 & pos) const {
	return std::make_shared<BoundingCircle>(translate_e(pos));
}

// Bodyの変換
IBodyPtr BoundingCircle::transform(const GSmatrix4 & mat) const {
	return std::make_shared<BoundingCircle>(transform_e(mat));
}

// Bodyの平行移動
BoundingCircle BoundingCircle::translate_e(const GSvector2 & pos) const {
	return BoundingCircle(mPosition + pos, mRadius);
}

// Bodyの変換
BoundingCircle BoundingCircle::transform_e(const GSmatrix4 & mat) const {
	return BoundingCircle(mPosition + GSvector2(mat.getPosition().x, mat.getPosition().y), mRadius * mat.getScale().y);
}

// 図形描画
void BoundingCircle::draw(const GSmatrix4 & mat) const{
	//DrawSphere3D(Vector3::Vector3ToVECTOR(mCenter), mRadius, 32, GetColor(255, 0, 0), GetColor(125, 125, 125), FALSE);
}

