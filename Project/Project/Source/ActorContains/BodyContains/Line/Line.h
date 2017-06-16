#ifndef LINE_H_
#define LINE_H_

#include "../Base/BodyBase.h"
#include <GSvector2.h>

namespace Body
{
	//線分クラス
	class Line :public BodyBase
	{
	public:
		//コンストラクタ
		Line(const GSvector2 vector);
		//デストラクタ
		~Line();
		//ベクトルの取得
		GSvector2 GetVector();

	protected:
		//軸平行矩形との衝突判定
		virtual bool IsCollide(AARectangle* other) override;
		//矩形との衝突判定
		virtual bool IsCollide(Body::Rectangle* other) override;
		//線分との衝突判定
		virtual bool IsCollide(Line* other) override;

	protected:
		GSvector2 m_Vector;	//ベクトル
	};
}
#endif