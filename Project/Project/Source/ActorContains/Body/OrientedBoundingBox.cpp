#include "OrientedBoundingBox.h"

#include "BoundingCircle.h"
#include "BoundingCapsule.h"
#include "BoundingSegment.h"
#include "BoundingBox.h"
#include "Ray.h"

#include "Base/HitInfo.h"
#include "Collision/Collision.h"

#include "../../Define/Def_Nagano.h"
#include "../../Define/Def_Nakayama.h"

#include <gslib.h>
#include <vector>

static const float EPSILON = 1e-3f;

//OBBの判定を作成
OrientedBoundingBox::OrientedBoundingBox(const GSvector2& position, const float & angle, const GSvector2 & extents) :
	Body(ShapeType::OBB, position, angle, extents){
	mAxis[0] = GSvector2(1.0f, 0.0f);
	mAxis[1] = GSvector2(0.0f, 1.0f);
	gsLoadTexture(1000, "Resource/Texture/wall.png");
	size = GSvector2(gsTextureGetWidth(gsGetTexture(1000)), gsTextureGetHeight(gsGetTexture(1000)));
}

//OBBの判定を作成(aabbを利用)
OrientedBoundingBox::OrientedBoundingBox(const BoundingBox & aabb) :
	OrientedBoundingBox(aabb.position(), 0.0f, aabb.extents()) {}

// 衝突判定
bool OrientedBoundingBox::isCollide(const IBody & other, HitInfo & hitinfo) const{
	// どちらかの判定を行わない場合false
	if (!other.enabled() || !enabled())return false;
	
	return other.intersects(*this, hitinfo);
}

// 衝突判定(球)
bool OrientedBoundingBox::intersects(const BoundingCircle & other, HitInfo & hitinfo) const{
	//Vector3 closest_point = ClosestPoint(other.position());
	//hitinfo.intersect = closest_point;
	return false;//other.contains(closest_point);
}

// 衝突判定(カプセル)
bool OrientedBoundingBox::intersects(const BoundingCapsule & other, HitInfo & hitinfo) const{
	return false;
}

// 衝突判定(線分)
bool OrientedBoundingBox::intersects(const BoundingSegment & other, HitInfo & hitinfo) const {
	GSvector2 line[2] = {};
	//GSvector2 segment[2] = { other. };

	//for (int i = 0; i < 4; i++) {
	//	line[0] = CornerPoint(i);
	//	line[1] = CornerPoint(i + 1);
	//	if (Collision::Segment_Segment(line, line, hitinfo.intersect)) {
	//		return true;

	//	}
	//}
	return false;//result;
}

// 衝突判定(AABB)
bool OrientedBoundingBox::intersects(const BoundingBox & other, HitInfo & hitinfo) const{
	return intersects(OrientedBoundingBox(other), hitinfo);
}

// 衝突判定(OBB)
bool OrientedBoundingBox::intersects(const OrientedBoundingBox & other, HitInfo & hitinfo) const {
	// 線分
	GSvector2 line1[2] = {};
	GSvector2 line2[2] = {};

	// 交点
	GSvector2 intersect;

	// 配列をクリア
	hitinfo.intersects.clear();

	// 各辺の交差判定
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			// 各辺を代入
			line1[0] = CornerPoint(i);
			line1[1] = CornerPoint(i + 1);
			// 各辺を代入
			line2[0] = other.CornerPoint(j);
			line2[1] = other.CornerPoint(j + 1);
			// 交差の判定
			if (Collision::Segment_Segment(line1, line2, intersect)) {
				//  最初の要素へのイテレータを返す
				auto itr = std::find(hitinfo.intersects.begin(), hitinfo.intersects.end(), intersect);
				// 発見できなかった場合
				if (itr == hitinfo.intersects.end()) {
					// 配列に交点情報を追加
					hitinfo.intersects.push_back(intersect);
				}
			}
		}
	}
	// 配列のサイズが0でない場合交差している
	return hitinfo.intersects.size() > 0;
}

// 衝突判定(レイ)
bool OrientedBoundingBox::intersects(const Ray & other, HitInfo & hitinfo) const {
	//BoundingBox aabb(-mExtents, mExtents);
	//const bool result = aabb.intersects(other.transform_e(WorldToLocal()), hitinfo);
	//if (result) {
	//	hitinfo.intersect = Vector3::Transform(hitinfo.intersect, LocalToWorld());
	//}
	return false;//result;
}

// Bodyの変換
IBodyPtr OrientedBoundingBox::transform(const Transform& transform) const {
	return std::make_shared<OrientedBoundingBox>(transform_e(transform));
}

// Bodyの変換
OrientedBoundingBox OrientedBoundingBox::transform_e(const Transform& transform) const{
	return OrientedBoundingBox(mTransform.m_Position + transform.m_Position, mTransform.m_Angle + transform.m_Angle, mExtents);
}

// 頂点
GSvector2 OrientedBoundingBox::CornerPoint(int cornerIndex) const {
	switch (cornerIndex) {
	default:
	case 0: return mTransform.m_Position + Rotate(GSvector2(-mExtents.x, -mExtents.y) * CHIP_SIZE / 2, mTransform.m_Angle);
	case 1: return mTransform.m_Position + Rotate(GSvector2(+mExtents.x, -mExtents.y) * CHIP_SIZE / 2, mTransform.m_Angle);
	case 2: return mTransform.m_Position + Rotate(GSvector2(+mExtents.x, +mExtents.y) * CHIP_SIZE / 2, mTransform.m_Angle);
	case 3: return mTransform.m_Position + Rotate(GSvector2(-mExtents.x, +mExtents.y) * CHIP_SIZE / 2, mTransform.m_Angle);
		// 0と同じ
	case 4: return mTransform.m_Position + Rotate(GSvector2(-mExtents.x, -mExtents.y) * CHIP_SIZE / 2, mTransform.m_Angle);
	}
}

// 矩形のサイズ
GSvector2 OrientedBoundingBox::Size() const{
	return mExtents * 2.0f;
}

// 中心座標
GSvector2 OrientedBoundingBox::Center() const{
	return mTransform.m_Position;
}

GSvector2 OrientedBoundingBox::Rotate(const GSvector2 & pos, const float & angle) const{
	return GSvector2(pos.x * gsCos(angle) - pos.y * gsSin(angle), pos.x * gsSin(angle) + pos.y * gsCos(angle));
}

// 図形描画
void OrientedBoundingBox::draw() const{
	// 描画
	gsDrawSprite2D(1000, &mTransform.m_Position, &GSrect(0, 0, size.x, size.y), &GSvector2(CHIP_SIZE / 2, CHIP_SIZE / 2), NULL, &mExtents, mTransform.m_Angle);

	//gsTextPos(CornerPoint(0).x, CornerPoint(0).y);
	//gsDrawText("a");
	//gsTextPos(CornerPoint(1).x, CornerPoint(1).y);
	//gsDrawText("a");
	//gsTextPos(CornerPoint(2).x, CornerPoint(2).y);
	//gsDrawText("a");
	//gsTextPos(CornerPoint(3).x, CornerPoint(3).y);
	//gsDrawText("a");

}
