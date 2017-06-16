#pragma once

#include "IBodyPtr.h"

#include "ShapeType.h"

struct GSvector2;
struct Transform;
struct HitInfo;

class BoundingCircle;
class BoundingCapsule;
class BoundingSegment;
class BoundingBox;
class OrientedBoundingBox;
class Ray;

// Bodyインターフェースクラス
class IBody {
public:
	// コンストラクタ
	IBody() {}
	// デストラクタ
	virtual ~IBody() = default;
public:
	// Bodyの変換
	virtual IBodyPtr transform(const Transform& matrix) const = 0;
	// 衝突判定
	virtual bool isCollide(const IBody& other, HitInfo& hitinfo) const = 0;
	// 衝突判定(球)
	virtual bool intersects(const BoundingCircle& other, HitInfo& hitinfo) const = 0;
	// 衝突判定(カプセル)
	virtual bool intersects(const BoundingCapsule& other, HitInfo& hitinfo) const = 0;
	// 衝突判定(線分)
	virtual bool intersects(const BoundingSegment& other, HitInfo& hitinfo) const = 0;
	// 衝突判定(AABB)
	virtual bool intersects(const BoundingBox& other, HitInfo& hitinfo) const = 0;
	// 衝突判定(AABB)
	virtual bool intersects(const OrientedBoundingBox& other, HitInfo& hitinfo) const = 0;
	// 衝突判定(レイ)
	virtual bool intersects(const Ray& other, HitInfo& hitinfo) const = 0;
	// 判定のON、OFF
	virtual void active(bool active) = 0;
	// 判定があるかどうか
	virtual bool enabled() const = 0;
	// 図形描画
	virtual void draw() const = 0;
	// 形状の取得
	virtual ShapeType type() const = 0;

	// 中心座標の取得
	virtual Transform transform() const = 0;
	// 座標の取得
	virtual GSvector2 position() const = 0;
	// 角度の取得
	virtual float angle() const = 0;
	// 前方ベクトルの取得
	virtual GSvector2 forward() const = 0;

	// 半径の取得
	virtual float radius() const = 0;
	// 長さの取得
	virtual float length() const = 0;
	// 方向の取得
	virtual GSvector2 direction() const = 0;
	// 縦幅の取得
	virtual float height() const = 0;
	// 横幅の取得
	virtual float width() const = 0;
	// 矩形の大きさの取得
	virtual GSvector2 extents() const = 0;
	// 矩形の軸の取得
	virtual GSvector2 axis(const int index) const = 0;
	// 点の取得
	virtual GSvector2 points(const int index) const = 0;
};

