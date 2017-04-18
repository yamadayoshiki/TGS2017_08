#pragma once

#include "Base/Body.h"

// AABB
class BoundingBox : public Body {
public:
	//AABBの判定を作成
	BoundingBox(const GSvector2& min, const GSvector2& max, const GSmatrix4 & mat);
public:
	// 衝突判定
	virtual bool isCollide(const IBody& other, HitInfo& hitinfo) const override;
	// 衝突判定(球)
	virtual bool intersects(const BoundingCircle& sphere, HitInfo& hitinfo) const override;
	// 衝突判定(カプセル)
	virtual bool intersects(const BoundingCapsule& capsule, HitInfo& hitinfo) const override;
	// 衝突判定(線分)
	virtual bool intersects(const BoundingSegment& segment, HitInfo& hitinfo) const override;
	// 衝突判定(AABB)
	virtual bool intersects(const BoundingBox& aabb, HitInfo& hitinfo) const override;
	// 衝突判定(レイ)
	virtual bool intersects(const Ray& ray, HitInfo& hitinfo) const override;

	// Bodyの平行移動
	virtual IBodyPtr translate(const GSvector2& pos) const override;
	// Bodyの変換
	virtual IBodyPtr transform(const GSmatrix4& mat) const override;

	// Bodyの平行移動
	BoundingBox translate_e(const GSvector2& pos) const;
	// Bodyの変換
	BoundingBox transform_e(const GSmatrix4& mat) const;

	// 線の衝突判定
	bool intersects(const GSvector2& position, const GSvector2& direction, float& start, float& end) const;
	// 近接点
	GSvector2 ClosestPoint(const GSvector2& target)const;
	// 頂点
	GSvector2 CornerPoint(int cornerIndex)const;
	// 矩形のサイズ
	GSvector2 Size()const;
	// 中心座標
	GSvector2 Center()const;

	// 図形描画
	virtual void draw(const GSmatrix4 & mat) const override;
};
