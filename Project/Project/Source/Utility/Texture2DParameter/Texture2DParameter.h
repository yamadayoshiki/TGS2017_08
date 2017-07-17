#ifndef TEXTURE2DPARAMETER_H_
#define TEXTURE2DPARAMETER_H_
#include <GStype.h>
//テクスチャ描画パラメーター構造体
struct Texture2DParameter {
	//コンストラクタ
	Texture2DParameter();
	~Texture2DParameter() {}
	struct {
		GSrect m_Rect;			//貼り付ける四角形
		GSvector2 m_Position;	//スクリーン座標
		GSvector2 m_Center;		//テクスチャの中心座標
		GScolor m_Color;		//テクスチャの色
		GSvector2 m_Scale;		//拡大縮小
		float m_Rotate;			//回転
	};
};

#endif