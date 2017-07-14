#include "Texture2DParameter.h"

Texture2DParameter::Texture2DParameter()
	: m_Rect(0, 0, 0, 0)				//貼り付ける四角形
	, m_Position(0.0f, 0.f)				//スクリーン座標
	, m_Center(0.0f, 0.0f)				//テクスチャの中心座標
	, m_Color(1.0f, 1.0f, 1.0f, 1.0f)	//テクスチャの色
	, m_Scale(1.0f, 1.0f)				//拡大縮小
	, m_Rotate(0.0f)					//回転
{
}