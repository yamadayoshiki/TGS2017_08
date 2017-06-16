#ifndef BODYBASE_H_
#define BODYBASE_H_

#include "../Interface/IBody.h"
#include "../../Transform/TransformPtr.h"
namespace Body
{
	//衝突判定図形先行宣言
	class AARectangle;
	class Line;
	class Rectangle;

	//衝突判定図形基底クラス
	class BodyBase : public Body::IBody
	{
	public:
		//コンストラクタ
		BodyBase(const BodyName name);
		//デストラクタ
		~BodyBase();

		//衝突しているか
		bool IsCollide(IBody* other) override;
		//名前の取得
		BodyName GetName() const override;
		//衝突可能かの取得
		bool IsExist() const override;
		//トランスフォームの設定
		virtual void SetTransform(const TransformPtr& transform);

	public:
		//衝突可能かの設定
		void SetExist(bool isExist);
		//トランスフォームの取得
		TransformPtr GetTransform() const;

	protected:
		//軸平行矩形との衝突判定
		virtual bool IsCollide(AARectangle* other) = 0;
		//矩形との衝突判定
		virtual bool IsCollide(Rectangle* other) = 0;
		//線分との衝突判定
		virtual bool IsCollide(Line* other) = 0;

	private:
		BodyName m_Name;			//名前
		bool m_IsExist;				//衝突可能か

	protected:
		TransformPtr p_Transform;	//トランスフォーム
	};
}
#endif
