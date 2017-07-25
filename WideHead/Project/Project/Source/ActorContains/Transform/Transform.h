#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include <GSvector2.h>

//トランスフォームクラス
class Transform {
public:
	//コンストラクタ
	Transform(GSvector2 pos, float angle);
	//デフォルトコンストラクタ
	Transform();
	//デストラクタ
	~Transform();
	//正面ベクトルを取得
	GSvector2 GetForward() const;

public:
	// 座標
	GSvector2 m_Position;
	// 回転角度
	float m_Angle;
};

#endif // !TRANSFORM_H_