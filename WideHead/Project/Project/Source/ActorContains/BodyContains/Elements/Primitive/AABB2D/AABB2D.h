#ifndef AABB2D_H_
#define AABB2D_H_
#include <GSvector2.h>
#include "../Interface/IPrimitive2D.h"
namespace Body
{
	//軸平行矩形
	struct AABB2D : public IPrimitive2D
	{
		struct
		{
			GSvector2 centerPoint;		//中心点
			GSvector2 halfLength;		//各軸半分の長さ

			GSvector2 staticHalfLength;
		};
		//コンストラクタ
		AABB2D(const GSvector2& centerPoint, const GSvector2& halfLength);
		//X軸の長さを取得
		float LengthX() const;
		//Y軸の長さを取得
		float LengthY() const;

		//名前の取得
		PrimitiveName GetName() const override;
		//座標、回転の設定
		void SetParam(const GSvector2& position, const float angle, const GSvector2& offsetVec)override;
		//衝突しているか
		Contact IsCollide(IPrimitive2D& p) override;
		//クローン生成
		IPrimitive2D* Clone() override;
	};

	inline AABB2D::AABB2D(const GSvector2 & centerPoint, const GSvector2 & halfLength)
		: centerPoint(centerPoint), halfLength(halfLength), staticHalfLength(halfLength) {
	}

	inline float AABB2D::LengthX() const {
		return halfLength.x * 2;
	}

	inline float AABB2D::LengthY() const {
		return halfLength.y * 2;
	}
	inline PrimitiveName AABB2D::GetName() const {
		return PrimitiveName::AABB2D;
	}

}

#endif