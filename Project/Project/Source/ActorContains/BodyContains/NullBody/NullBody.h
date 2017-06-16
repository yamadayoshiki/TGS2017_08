#ifndef NULLBODY_H_
#define NULLBODY_H_
#include "../Interface/IBody.h"
#include "../BodyName.h"

namespace Body
{
	//何もない衝突判定図形
	class NullBody : public IBody
	{
	public:
		//コンストラクタ
		NullBody() {}
		//衝突しているか
		bool IsCollide(IBody* other) override { return false; }
		//名前の取得
		BodyName GetName() const override { return BodyName::None; }
		//衝突可能かの取得
		virtual bool IsExist() const { return false; };
		//トランスフォームの設定
		virtual void SetTransform(const TransformPtr& transform) {};
	};
}

#endif // !NULLBODY_H_
