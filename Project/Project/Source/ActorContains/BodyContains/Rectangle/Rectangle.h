#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "../Base/BodyBase.h"

namespace Body
{
	//矩形クラス
	class Rectangle : public BodyBase
	{
	public:
		//コンストラクタ
		Rectangle(
			const float width,
			const float height);
		//デストラクタ
		~Rectangle();
		//横幅の取得
		float GetWidth();
		//縦幅の取得
		float GetHeigh();

	protected:
		//軸平行矩形との衝突判定
		virtual bool IsCollide(AARectangle* other) override;
		//矩形との衝突判定
		virtual bool IsCollide(Rectangle* other) override;
		//線分との衝突判定
		virtual bool IsCollide(Line* other) override;

	protected:
		float m_Width;	//横幅
		float m_Heigh;	//縦幅
	};
}
#endif // !RECTANGLE_H_
