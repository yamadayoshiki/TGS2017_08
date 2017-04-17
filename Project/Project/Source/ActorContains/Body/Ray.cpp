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

// 衝突判定(レイ)
bool Ray::intersects(const Ray & other, HitInfo & hitinfo) const{
	return false;
}

// Bodyの平行移動
IBodyPtr Ray::translate(const GSvector2 & pos) const {
	return std::make_shared<Ray>(translate_e(pos));
}

// Bodyの変換
IBodyPtr Ray::transform(const GSmatrix4 & mat) const {
	return std::make_shared<Ray>(transform_e(mat));
}

// Bodyの平行移動
Ray Ray::translate_e(const GSvector2 & pos) const {
	return Ray(mPosition + pos, mDirection);
}

// Bodyの変換
Ray Ray::transform_e(const GSmatrix4 & mat) const {
	return Ray(mPosition + GSvector2(mat.getPosition().x, mat.getPosition().y), mDirection);
}

// 図形描画
void Ray::draw(const GSmatrix4 & mat) const{}
