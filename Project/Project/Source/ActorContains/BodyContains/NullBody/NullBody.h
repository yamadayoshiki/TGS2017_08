#ifndef NULLBODY_H_
#define NULLBODY_H_
#include "../Interface/IBody.h"
namespace Body
{
	//何もない衝突判定図形
	class NullBody : public IBody
	{
	public:
		//コンストラクタ
		NullBody() {}
		//衝突しているか
		ContactSet IsCollide(IBody* other) override;
		//トランスフォームの設定
		void SetTransform(const TransformPtr& transform)override {}
		//衝突可能かの設定
		void SetExist(bool isExist) override {}
		//形状の追加
		void AddShape(const IPrimitive2DSPtr& p, const GSvector2& offsetPos, float offsetAngle) override {}
		//AABBの設定
		void SetAABB(const GSvector2& AABBHalf) {};
		//クローン生成
		IBodyPtr Clone(const MotionType type) { return std::shared_ptr<NullBody>(); }
		//変形
		void Transform(const BodyCollidable& bodyCollidable) override {}
		//形状管理の取得
		BodyCollidable GetBodyCollidable() override;
		//衝突可能かの設定
		virtual bool GetExist() const override { return false; }
	};
}

#endif // !NULLBODY_H_