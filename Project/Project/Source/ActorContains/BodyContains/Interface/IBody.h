#ifndef IBODY_H_
#define IBODY_H_
#include "IBodyPtr.h"
#include "../../Transform/TransformPtr.h"
#include "../Elements/MotionType.h"
#include "../Elements/Primitive/Interface/IPrimitive2DPtr.h"
struct GSvector2;
namespace Body
{
	struct ContactSet;
	class IBody
	{
	public:
		//衝突しているか
		virtual ContactSet IsCollide(IBody* other) = 0;
		//トランスフォームの設定
		virtual void SetTransform(const TransformPtr& transform) = 0;
		//衝突可能かの設定
		virtual void SetExist(bool isExist) = 0;
		//形状の追加
		virtual void AddShape(const IPrimitive2DSPtr& p, const GSvector2& offsetPos, float offsetAngle) = 0;
		//AABBの設定
		virtual void SetAABB(const GSvector2& AABBHalf) = 0;
		//クローン生成
		virtual IBodyPtr Clone(const MotionType type) = 0;
	};
}
#endif