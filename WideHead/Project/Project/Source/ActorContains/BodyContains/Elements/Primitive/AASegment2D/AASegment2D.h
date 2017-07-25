#ifndef AASEGMENT_H_
#define AASEGMENT_H_
#include <GSvector2.h>
#include "../Interface/IPrimitive2D.h"
//軸平行線分
namespace Body
{
	//線分
	struct AASegment2D : public IPrimitive2D
	{
		GSvector2 point;	//始点
		GSvector2 vector;	//ベクトル
		const GSvector2 staticVector;

		//コンストラクタ
		AASegment2D(const GSvector2& point, const GSvector2& vector);
		//デストラクタ
		~AASegment2D();
		//終点を取得
		GSvector2 GetEndPoint() const;
		//X軸の長さを取得
		float LengthX() const;
		//Y軸の長さを取得
		float LengthY() const;

		//名前の取得
		PrimitiveName GetName() const override;
		//座標、回転の設定
		void SetParam(const GSvector2& position, const float angle, const GSvector2& offsetVec) override;
		//衝突しているか
		Contact IsCollide(IPrimitive2D& p) override;
		//クローン生成
		IPrimitive2D* Clone() override;
	};

	inline AASegment2D::AASegment2D(const GSvector2& point, const GSvector2& vector)
		: point(point), vector(vector), staticVector(vector) {
	}

	inline AASegment2D::~AASegment2D() {
	}

	inline GSvector2 AASegment2D::GetEndPoint() const {
		return point + vector;
	}
	inline float AASegment2D::LengthX() const {
		return fabs(vector.x);
	}
	inline float AASegment2D::LengthY() const {
		return fabs(vector.y);
	}
}
#endif // !AASEGMENT_H_
