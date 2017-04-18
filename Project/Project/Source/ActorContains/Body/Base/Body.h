#pragma once

#include "IBody.h"
#include <GStype.h>
#include <GSmatrix4.h>

class Body : public IBody {
public:
	// コンストラクタ
	Body() : mType(ShapeType::None), mPosition(GSvector2(0, 0)), mMatrix(GS_MATRIX4_IDENTITY), mRadius(0.0f), mLength(0.0f), mDirection(GSvector2(0, 0)), mHeight(0.0f), mWidth(0.0f), mDepth(0.0f), mMin(GSvector2(0, 0)), mMax(GSvector2(0, 0)), mExtents(GSvector2(0, 0)), mEnabled(false){}
	// コンストラクタ(球)
	Body(const ShapeType& type, const GSvector2& position, const float& radius) :
		mType(type), mPosition(position), mMatrix(GS_MATRIX4_IDENTITY), mRadius(radius), mLength(0.0f), mDirection(GSvector2(0, 0)), mHeight(0.0f), mWidth(0.0f), mDepth(0.0f), mMin(GSvector2(0, 0)), mMax(GSvector2(0, 0)), mExtents(GSvector2(0, 0)), mEnabled(true) {}
	// コンストラクタ(線分)
	Body(const ShapeType& type, const GSvector2& position, const GSmatrix4& mat, const float& length) :
		mType(type), mPosition(position), mMatrix(mat), mRadius(0.0f), mLength(length), mDirection(GSvector2(0, 0)), mHeight(0.0f), mWidth(0.0f), mDepth(0.0f), mMin(GSvector2(0, 0)), mMax(GSvector2(0, 0)), mExtents(GSvector2(0, 0)), mEnabled(true) {}
	// コンストラクタ(レイ)
	Body(const ShapeType& type, const GSvector2& position, const GSmatrix4& mat, const GSvector2& direction) :
		mType(type), mPosition(position), mMatrix(GS_MATRIX4_IDENTITY), mRadius(0.0f), mLength(0.0f), mDirection(direction), mHeight(0.0f), mWidth(0.0f), mDepth(0.0f), mMin(GSvector2(0, 0)), mMax(GSvector2(0, 0)), mExtents(GSvector2(0, 0)), mEnabled(true) {}
	// コンストラクタ(カプセル)
	Body(const ShapeType& type, const GSvector2& position, const GSmatrix4& mat, const float& radius, const float& length) :
		mType(type), mPosition(position), mMatrix(mat), mRadius(radius), mLength(length), mDirection(GSvector2(0, 0)), mHeight(0.0f), mWidth(0.0f), mDepth(0.0f), mMin(GSvector2(0, 0)), mMax(GSvector2(0, 0)), mExtents(GSvector2(0, 0)), mEnabled(true) {}
	// コンストラクタ(AABB)
	Body(const ShapeType& type, const GSvector2& position, const GSvector2 & min, const GSvector2 & max, const GSmatrix4& mat) :
		mType(type), mPosition(position), mMatrix(mat), mRadius(0.0f), mLength(0.0f), mDirection(GSvector2(0, 0)), mHeight(0.0f), mWidth(0.0f), mDepth(0.0f), mMin(min), mMax(max), mExtents(GSvector2(0, 0)), mEnabled(true) {}
	// デストラクタ
	virtual ~Body(){}

	// 判定のON、OFF
	virtual void active(bool active) override { mEnabled = active; }
	// 判定があるかどうか
	virtual bool enabled() const override { return mEnabled; }

	// 形状の取得
	virtual ShapeType type() const override { return mType; }
	// 中心座標の取得
	virtual GSvector2 position() const override { return mPosition; }
	// 変換行列の取得
	virtual GSmatrix4 matrix() const override { return mMatrix; }
	// 半径の取得
	virtual float radius() const override { return mRadius; }
	// 長さの取得
	virtual float length() const override { return mLength; }
	// 方向の取得
	virtual GSvector2 direction() const override { return mDirection; }

	// 縦幅の取得
	virtual float height() const override { return mHeight; }
	// 横幅の取得
	virtual float width() const override { return mWidth; }
	// 奥行の取得
	virtual float depth() const override { return mDepth; }
	// 矩形の最小点の取得
	virtual GSvector2 box_min() const override { return mMin; }
	// 矩形の最大点の取得
	virtual GSvector2 box_max() const override { return mMax; }
	// 矩形の大きさの取得
	virtual GSvector2 extents() const override { return mExtents; }
	// 矩形の軸の取得
	virtual GSvector2 axis(const int index) const override { return mAxis[index]; }
	// 点の取得
	virtual GSvector2 points(const int index) const override { return mPoints[index]; }
	
protected:
	// 形状
	ShapeType mType;
	// 中心座標
	GSvector2 mPosition;
	// 変換行列
	GSmatrix4 mMatrix;
	// 半径
	float mRadius;
	// 長さ
	float mLength;

	// レイ用
	// 方向
	GSvector2 mDirection;
	
	// ボックス用
	// 縦幅
	float mHeight;
	// 横幅
	float mWidth;
	// 奥行
	float mDepth;

	// 矩形の最小点
	GSvector2 mMin;
	// 矩形の最大点
	GSvector2 mMax;

	// 矩形の大きさ
	GSvector2 mExtents;
	// 矩形の軸
	GSvector2 mAxis[3];

	// 点
	GSvector2 mPoints[4];

	// 判定があるかどうか
	bool mEnabled;
};

