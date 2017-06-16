#ifndef AARECTANGLE_H_
#define AARECTANGLE_H_

#include "../Base/BodyBase.h"

namespace Body
{
	//軸平行矩形
	class AARectangle : public BodyBase
	{
	public:
		//コンストラクタ
		AARectangle(
			const float width,
			const float height);
		//デストラクタ
		~AARectangle();
		//横幅の取得
		virtual float GetWidth();
		//縦幅の取得
		virtual float GetHeigh();

	protected:
		//軸平行矩形との衝突判定
		virtual bool IsCollide(Body::AARectangle* other) override;
		//矩形との衝突判定
		virtual bool IsCollide(Body::Rectangle* other) override;
		//線分との衝突判定
		virtual bool IsCollide(Body::Line* other) override;

	protected:
		float m_Width;	//横幅
		float m_Heigh;	//縦幅
	};
}

#endif // !AARECTANGLE_H_
