#ifndef IBODY_H_
#define IBODY_H_
#include "../../Transform/TransformPtr.h"

enum class BodyName;
namespace Body
{
	class IBody
	{
	public:
		//衝突しているか
		virtual bool IsCollide(IBody* other) = 0;
		//名前の取得
		virtual BodyName GetName() const = 0;
		//衝突可能かの取得
		virtual bool IsExist() const = 0;
		//トランスフォームの設定
		virtual void SetTransform(const TransformPtr& transform) = 0;
	};
}
#endif // !IBODY_H_
