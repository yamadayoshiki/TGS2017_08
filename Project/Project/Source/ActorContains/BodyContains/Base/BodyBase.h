#ifndef BODYBASE_H_
#define BODYBASE_H_
#include "../Interface/IBody.h"
#include "../../Transform/TransformPtr.h"
#include "../Elements/Collidable/BodyCollidable.h"
#include <GSvector2.h>
#include "../../../Utility/Contact/Contact.h"
#include "../Elements/MotionType.h"
namespace Body
{
	struct ContactSet;
	//衝突判定図形基底クラス
	class BodyBase : public Body::IBody
	{
	public:
		//コンストラクタ
		explicit BodyBase(const MotionType type = MotionType::None);
		//デストラクタ
		~BodyBase();

		//衝突しているか
		ContactSet IsCollide(IBody* other) override;
		//トランスフォームの設定
		virtual void SetTransform(const TransformPtr& transform) override;
		//衝突可能かの設定
		void SetExist(bool isExist) override;
		//追加
		void AddShape(const IPrimitive2DSPtr& p, const GSvector2& offsetPos, float offsetAngle) override;
		//AABBの設定
		void SetAABB(const GSvector2& AABBHalf) override;
		//クローン生成
		IBodyPtr Clone(const MotionType type) override;
		//変形
		void Transform(const BodyCollidable& bodyCollidable)override;
		//形状管理の取得
		BodyCollidable GetBodyCollidable() override;
	public:
		//衝突しているか
		ContactSet IsCollide(BodyBase* other);
		//衝突可能かの取得
		bool IsExist() const;
		//トランスフォームの取得
		TransformPtr GetTransform() const;

	private:
		bool m_IsExist;				//衝突可能か
		MotionType m_Type;			//タイプ
		BodyCollidable m_Collidable;//形状管理

	protected:
		TransformPtr p_Transform;	//トランスフォーム
	};
}
#endif
