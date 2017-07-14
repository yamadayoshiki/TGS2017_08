#ifndef IPRIMITIVE2D_H_
#define IPRIMITIVE2D_H_
#include "..\PrimitiveName.h"
struct GSvector2;
namespace Body
{
	struct Contact;
	//２Dプリミティブインターフェイス
	struct IPrimitive2D
	{
		//名前の取得
		virtual PrimitiveName GetName() const = 0;
		//座標、回転の設定
		virtual void SetParam(const GSvector2& position, const float angle, const GSvector2& offsetVec) = 0;
		//衝突しているか
		virtual Contact IsCollide(IPrimitive2D& p) = 0;
		//クローン生成
		virtual IPrimitive2D* Clone() = 0;
	};
}
#endif // !IPRIMITIVE2D_H_
