#pragma once

#include "Base/Body.h"

// OBB
class OrientedBoundingBox : public Body {
public:
	//OBBの判定を作成
	OrientedBoundingBox(const GSvector2& position, const float & angle, const GSvector2 & extents);
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
	virtual IBodyPtr transform(const Transform& transform) const override;

	// Bodyの変換
	OrientedBoundingBox transform_e(const Transform& transform) const;

	// 頂点
	GSvector2 CornerPoint(int cornerIndex)const;
	// 矩形のサイズ
	GSvector2 Size()const;
	// 中心座標
	GSvector2 Center()const;
	// 回転
	GSvector2 Rotate(const GSvector2& pos, const float& angle)const;
	
	// 図形描画
	virtual void draw() const override;

	// 画像サイズ
	GSvector2 size;
};