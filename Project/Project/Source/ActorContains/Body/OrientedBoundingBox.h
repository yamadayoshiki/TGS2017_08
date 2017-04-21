#pragma once

#include "Base/Body.h"

// OBB
class OrientedBoundingBox : public Body {
public:
	//OBBの判定を作成
	OrientedBoundingBox(const GSvector2& position, const GSvector2& extents, const GSmatrix4& matrix);
	//OBBの判定を作成(aabbを利用)
	explicit OrientedBoundingBox(const BoundingBox& aabb);
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
	virtual IBodyPtr transform(const GSmatrix4& mat) const override;

	// Bodyの変換
	OrientedBoundingBox transform_e(const GSmatrix4& mat) const;

	// 近接点
	GSvector2 ClosestPoint(const GSvector2& target)const;
	// 頂点
	GSvector2 CornerPoint(int cornerIndex)const;
	// 矩形のサイズ
	GSvector2 Size()const;
	// 中心座標
	GSvector2 Center()const;

	// ローカル座標へ変換
	GSmatrix4 LocalToWorld() const;
	// ワールド座標へ変換
	GSmatrix4 WorldToLocal() const;
	
	GSvector2 size;

	// 図形描画
	virtual void draw() const override;
};