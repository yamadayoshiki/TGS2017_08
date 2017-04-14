#include "BoundingBox.h"
#include "BoundingCircle.h"
#include "BoundingCapsule.h"
#include "BoundingSegment.h"
#include "Ray.h"

#include <cmath>
#include <algorithm>
#include <limits>

#include "Base/HitInfo.h"
//#include "../Collision/Collision.h"

//AABBの判定を作成
BoundingBox::BoundingBox(const GSvector2 & min, const GSvector2 & max) :
	Body(ShapeType::Box, (max + min) / 2.0f, min, max){}

// 衝突判定
bool BoundingBox::isCollide(const IBody & other, HitInfo & hitinfo) const {
	// どちらかの判定を行わない場合false
	if (!other.enabled() || !enabled())return false;

	return other.intersects(*this, hitinfo);
}

// 衝突判定(球)
bool BoundingBox::intersects(const BoundingCircle & sphere, HitInfo & hitinfo) const{
	const GSvector2 point = ClosestPoint(sphere.position());
	hitinfo.intersect = point;
	return false;// sphere.contains(point);
}

// 衝突判定(カプセル)
bool BoundingBox::intersects(const BoundingCapsule & capsule, HitInfo & hitinfo) const{
	return false;
}

// 衝突判定(線分)
bool BoundingBox::intersects(const BoundingSegment & segment, HitInfo & hitinfo) const{
	float near_ = 0.0f;
	float far_ = segment.length();
	const GSvector2 direction = segment.Direction();
	const bool result = intersects(segment.points(0), direction, near_, far_);
	if (result) {
		hitinfo.intersect = segment.points(0) + direction * near_;
	}
	return result;
}

// 衝突判定(AABB)
bool BoundingBox::intersects(const BoundingBox & aabb, HitInfo & hitinfo) const{
	return	mMin.x < aabb.mMax.x && mMin.y < aabb.mMax.y && 
			aabb.mMin.x < mMax.x && aabb.mMin.y < mMax.y;
}

// 衝突判定(レイ)
bool BoundingBox::intersects(const Ray & ray, HitInfo & hitinfo) const{
	float start = 0.0f;
	float end = 0.00001f;// std::numeric_limits<float>::max();
	const bool result = intersects(ray.position(), ray.direction(), start, end);
	if (result) {
		hitinfo.intersect = ray.position() + ray.direction() * start;
	}
	return result;
}

// Bodyの平行移動
IBodyPtr BoundingBox::translate(const GSvector2 & pos) const{
	return std::make_shared<BoundingBox>(translate_e(pos));
}

// Bodyの変換
IBodyPtr BoundingBox::transform(const GSmatrix4 & mat) const{
	return std::make_shared<BoundingBox>(transform_e(mat));
}

// Bodyの平行移動
BoundingBox BoundingBox::translate_e(const GSvector2 & pos) const{
	return BoundingBox(mMin + pos, mMax + pos);
}

// Bodyの変換
BoundingBox BoundingBox::transform_e(const GSmatrix4 & mat) const{
	return BoundingBox(mMin, mMax);
}

// 線の衝突判定
bool BoundingBox::intersects(const GSvector2 & position, const GSvector2 & direction, float & start, float & end) const{
	////xスラブ
	//if (std::abs(direction.x) > std::numeric_limits<float>::epsilon()) {
	//	const float t1 = (mMin.x - position.x) / direction.x;
	//	const float t2 = (mMax.x - position.x) / direction.x;
	//	if (t1 < t2) {
	//		start = std::max<float>(t1, start);
	//		end = std::min<float>(t2, end);
	//	}
	//	else {
	//		start = std::max<float>(t2, start);
	//		end = std::min<float>(t1, end);
	//	}
	//	if (start > end) {
	//		return false;
	//	}
	//}
	//else if (position.x < mMin.x || position.x > mMax.x) {
	//	return false;
	//}
	////yスラブ
	//if (std::abs(direction.y) > std::numeric_limits<float>::epsilon()) {
	//	const float t1 = (mMin.y - position.y) / direction.y;
	//	const float t2 = (mMax.y - position.y) / direction.y;
	//	if (t1 < t2) {
	//		start = std::max<float>(t1, start);
	//		end = std::min<float>(t2, end);
	//	}
	//	else {
	//		start = std::max<float>(t2, start);
	//		end = std::min<float>(t1, end);
	//	}
	//	if (start > end) {
	//		return false;
	//	}
	//}
	//else if (position.y < mMin.y || position.y > mMax.y) {
	//	return false;
	//}
	////zスラブ
	//if (std::abs(direction.z) > std::numeric_limits<float>::epsilon()) {
	//	const float t1 = (mMin.z - position.z) / direction.z;
	//	const float t2 = (mMax.z - position.z) / direction.z;
	//	if (t1 < t2) {
	//		start = std::max<float>(t1, start);
	//		end = std::min<float>(t2, end);
	//	}
	//	else {
	//		start = std::max<float>(t2, start);
	//		end = std::min<float>(t1, end);
	//	}
	//	if (start > end) {
	//		return false;
	//	}
	//}
	//else if (position.z < mMin.z || position.z > mMax.z) {
	//	return false;
	//}
	return false;
}

// 近接点
GSvector2 BoundingBox::ClosestPoint(const GSvector2 & target) const{
	return target.clamp(mMin, mMax);
}

// 頂点
GSvector2 BoundingBox::CornerPoint(int cornerIndex) const{
	switch (cornerIndex) {
	default:
	case 0: return mMin;
	case 1: return GSvector2(mMin.x, mMax.y);
	case 2: return GSvector2(mMax.x, mMin.y);
	case 3: return mMax;
	}
}

// 矩形のサイズ
GSvector2 BoundingBox::Size() const{
	return mMax - mMin;
}

// 中心座標
GSvector2 BoundingBox::Center() const{
	return (mMax + mMin) / 2.0f;
}

// 図形描画
void BoundingBox::draw() const{
}
