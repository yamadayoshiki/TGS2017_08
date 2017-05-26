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


//貼り付ける四角形の設定
void Texture2DParameter::SetRect(const GSrect& rect)
{
	m_Rect = rect;
}

//貼り付ける四角形の取得
GSrect Texture2DParameter::GetRect() const
{
	return m_Rect;
}

//スクリーン座標の設定
void Texture2DParameter::SetPosition(const GSvector2 position)
{
	m_Position = position;
}

//スクリーン座標の取得
GSvector2 Texture2DParameter::GetPosition() const
{
	return m_Position;
}

//テクスチャの中心座標の設定
void Texture2DParameter::SetCenter(const GSvector2 center)
{
	m_Center = center;
}

//テクスチャの中心座標の取得
GSvector2 Texture2DParameter::GetCenter() const
{
	return m_Center;
}


//テクスチャの色の設定
void Texture2DParameter::SetColor(const GScolor& color)
{
	m_Color = color;
}

//テクスチャの色の取得
GScolor Texture2DParameter::GetColor() const
{
	return m_Color;
}

//拡大縮小の設定
void Texture2DParameter::SetScale(const GSvector2 scale)
{
	m_Scale = scale;
}

//拡大縮小の取得
GSvector2 Texture2DParameter::GetScale() const
{
	return m_Scale;
}

//回転の設定
void Texture2DParameter::SetRotate(const float rotate)
{
	m_Rotate = rotate;
}

//回転の取得
float Texture2DParameter::GetRotate() const
{
	return m_Rotate;
}