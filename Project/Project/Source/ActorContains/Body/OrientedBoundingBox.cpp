#include "OrientedBoundingBox.h"

#include <gslib.h>
#include <vector>

#include "BoundingCircle.h"
#include "BoundingCapsule.h"
#include "BoundingSegment.h"
#include "BoundingBox.h"
#include "Ray.h"

#include "Base/HitInfo.h"
#include "../Collision/Collision.h"

#include "../../Define/Def_Nagano.h"
#include "../../Define/Def_Nakayama.h"

static const float EPSILON = 1e-3f;

//OBBの判定を作成
OrientedBoundingBox::OrientedBoundingBox(const GSvector2 & position, const GSvector2 & extents, const GSmatrix4& matrix) :
	Body(ShapeType::OBB, position, extents, matrix){
	mAxis[0] = GSvector2(1.0f, 0.0f);
	mAxis[1] = GSvector2(0.0f, 1.0f);
	gsLoadTexture(0, "Resource/Texture/wall.png");
	size = GSvector2(gsTextureGetWidth(gsGetTexture(0)), gsTextureGetHeight(gsGetTexture(0)));
}

//OBBの判定を作成(aabbを利用)
OrientedBoundingBox::OrientedBoundingBox(const BoundingBox & aabb) :
	Body(ShapeType::OBB, GSvector2(0, 0), GSvector2(1.0f, 1.0f), GS_MATRIX4_IDENTITY) {
	mAxis[0] = GSvector2(1.0f, 0.0f);
	mAxis[1] = GSvector2(0.0f, 1.0f);
}

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
	return false;// intersects(OrientedBoundingBox(other), hitinfo);
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
IBodyPtr OrientedBoundingBox::transform(const GSmatrix4 & mat) const {
	return std::make_shared<OrientedBoundingBox>(transform_e(mat));
}

// Bodyの変換
OrientedBoundingBox OrientedBoundingBox::transform_e(const GSmatrix4 & mat) const{
	//const Vector3 scale = mat.Scale();
	return OrientedBoundingBox(mPosition + GSvector2(mat.getPosition()), mExtents, mat);
}

// 近接点
GSvector2 OrientedBoundingBox::ClosestPoint(const GSvector2 & target) const{
	//const Vector3& d = target - mPosition;
	GSvector2 result = mPosition;
	//result += MathHelper::Clamp(Vector3::Dot(d, mAxis[0]), -mExtents.x, mExtents.x) * mAxis[0];
	//result += MathHelper::Clamp(Vector3::Dot(d, mAxis[1]), -mExtents.y, mExtents.y) * mAxis[1];
	//result += MathHelper::Clamp(Vector3::Dot(d, mAxis[2]), -mExtents.z, mExtents.z) * mAxis[2];
	return result;
}

// 頂点
GSvector2 OrientedBoundingBox::CornerPoint(int cornerIndex) const {
	switch (cornerIndex) {
	default:
	case 0: return mPosition + GSvector2(-mExtents.x, -mExtents.y) * CHIP_SIZE / 2 * mMatrix.getRotateMatrix();
	case 1: return mPosition + GSvector2(+mExtents.x, -mExtents.y) * CHIP_SIZE / 2 * mMatrix.getRotateMatrix();
	case 2: return mPosition + GSvector2(+mExtents.x, +mExtents.y) * CHIP_SIZE / 2 * mMatrix.getRotateMatrix();
	case 3: return mPosition + GSvector2(-mExtents.x, +mExtents.y) * CHIP_SIZE / 2 * mMatrix.getRotateMatrix();
	// 0と同じ
	case 4: return mPosition + GSvector2(-mExtents.x, -mExtents.y) * CHIP_SIZE / 2 * mMatrix.getRotateMatrix();
	}
}

// 矩形のサイズ
GSvector2 OrientedBoundingBox::Size() const{
	return mExtents * 2.0f;
}

// 中心座標
GSvector2 OrientedBoundingBox::Center() const{
	return mPosition;
}

// ローカル座標へ変換
GSmatrix4 OrientedBoundingBox::LocalToWorld() const {
	return GSmatrix4(GS_MATRIX4_IDENTITY
		//mAxis[0].x, mAxis[0].y, mAxis[0].z, 0.0f,
		//mAxis[1].x, mAxis[1].y, mAxis[1].z, 0.0f,
		//mAxis[2].x, mAxis[2].y, mAxis[2].z, 0.0f,
		//mPosition.x, mPosition.y, mPosition.z, 1.0f
		);
}

// ワールド座標へ変換
GSmatrix4 OrientedBoundingBox::WorldToLocal() const {
	return GSmatrix4(GS_MATRIX4_IDENTITY);// Matrix::InvertFast(LocalToWorld());
}

// 図形描画
void OrientedBoundingBox::draw() const{
	// 回転角度
	GSvector3 angle = GSvector3(mMatrix.getRoll(), mMatrix.getPitch(), mMatrix.getYaw());
	// 描画
	gsDrawSprite2D(0, &mPosition, &GSrect(0, 0, size.x, size.y), &GSvector2(CHIP_SIZE / 2, CHIP_SIZE / 2), NULL, &mExtents, 90 + mMatrix.getRoll());
}
