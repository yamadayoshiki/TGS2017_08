#pragma once

#include "Body.h"

// 判定なしBody
class DammyBody : public Body{
public:
	// コンストラクタ
	DammyBody() {}
	// Bodyの平行移動
	virtual IBodyPtr translate(const GSvector2& position) const override { return std::make_shared<DammyBody>(); }
	// Bodyの変換
	virtual IBodyPtr transform(const GSmatrix4& matrix) const override { return std::make_shared<DammyBody>(); }
	// 衝突判定
	virtual bool isCollide(const IBody& other, HitInfo& hitinfo) const override { return false; }
	// 衝突判定(球)
	virtual bool intersects(const BoundingCircle& other, HitInfo& hitinfo) const override { return false; }
	// 衝突判定(カプセル)
	virtual bool intersects(const BoundingCapsule& other, HitInfo& hitinfo) const override { return false; }
	// 衝突判定(線分)
	virtual bool intersects(const BoundingSegment& other, HitInfo& hitinfo) const override { return false; }
	// 衝突判定(AABB)
	virtual bool intersects(const BoundingBox& other, HitInfo& hitinfo) const override { return false; }
	// 衝突判定(レイ)
	virtual bool intersects(const Ray& other, HitInfo& hitinfo) const override { return false; }
	// 図形描画
	virtual void draw() const override{}
};
