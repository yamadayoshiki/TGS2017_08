#pragma once

#include "Base/Body.h"

// レイ
class Ray : public Body {
public:
	// コンストラクタ
	Ray(const GSvector2& position, const GSvector2& direction);
public:
	// 衝突判定
	virtual bool isCollide(const IBody& other, HitInfo& hitinfo) const override;
	// 衝突判定(球)
	virtual bool intersects(const BoundingCircle& other, HitInfo& hitinfo) const override;
	// 衝突判定(カプセル)
	virtual bool intersects(const BoundingCapsule& other, HitInfo& hitinfo) const override;
	// 衝突判定(線分)
	virtual bool intersects(const BoundingSegment& other, HitInfo& hitinfo) const override;
	// 衝突判定(AABB)
	virtual bool intersects(const BoundingBox& other, HitInfo& hitinfo) const override;
	// 衝突判定(レイ)
	virtual bool intersects(const Ray& other, HitInfo& hitinfo) const override;

	// Bodyの平行移動
	virtual IBodyPtr translate(const GSvector2& pos) const override;
	// Bodyの変換
	virtual IBodyPtr transform(const GSmatrix4& mat) const override;

	// Bodyの平行移動
	Ray translate_e(const GSvector2& pos) const;
	// Bodyの変換
	Ray transform_e(const GSmatrix4& mat) const;

	// 図形描画
	virtual void draw() const override;
};