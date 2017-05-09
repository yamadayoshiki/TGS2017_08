#pragma once

#include "Base/Body.h"

class BoundingCircle : public Body {
public:
	//球の判定を作成
	BoundingCircle(const GSvector2& pos, const float& rad);
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
	// 衝突判定(OBB)
	virtual bool intersects(const OrientedBoundingBox& other, HitInfo& hitinfo) const override;
	// 衝突判定(レイ)
	virtual bool intersects(const Ray& other, HitInfo& hitinfo) const override;

	// Bodyの変換
	virtual IBodyPtr transform(const Transform& transform) const override;

	// Bodyの変換
	BoundingCircle transform_e(const Transform& transform) const;

	// 図形描画
	virtual void draw() const override;
};
