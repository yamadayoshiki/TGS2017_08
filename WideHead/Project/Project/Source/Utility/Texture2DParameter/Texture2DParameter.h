#ifndef TEXTURE2DPARAMETER_H_
#define TEXTURE2DPARAMETER_H_
#include "Texture2DParameterPtr.h"
#include <GStype.h>
//テクスチャ描画パラメーター構造体
struct Texture2DParameter {
	//コンストラクタ
	Texture2DParameter();
	~Texture2DParameter();
	struct {
		GSrect		m_Rect;			//貼り付ける四角形
		GSvector2	m_Position;		//スクリーン座標
		GSvector2	m_Center;		//テクスチャの中心座標
		GScolor		m_Color;		//テクスチャの色
		GSvector2	m_Scale;		//拡大縮小
		float		m_Rotate;		//回転
	};

	Texture2DParameterSPtr Clone() {
		Texture2DParameterSPtr result = std::make_shared<Texture2DParameter>();
		result->m_Rect = m_Rect;
		result->m_Position = m_Position;
		result->m_Center = m_Center;
		result->m_Color = m_Color;
		result->m_Scale = m_Scale;
		result->m_Rotate = m_Rotate;
		return result;
	}

	void Copy(const Texture2DParameterSPtr& source) {
		m_Rect = source->m_Rect;
		m_Position = source->m_Position;
		m_Center = source->m_Center;
		m_Color = source->m_Color;
		m_Scale = source->m_Scale;
		m_Rotate = source->m_Rotate;
	}
};

#endif