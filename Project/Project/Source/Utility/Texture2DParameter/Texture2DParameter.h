#ifndef TEXTURE2DPARAMETER_H_
#define TEXTURE2DPARAMETER_H_

#include <gslib.h>

//テクスチャ描画パラメーター構造体
class Texture2DParameter
{
public:
	//コンストラクタ
	Texture2DParameter();

	//貼り付ける四角形の設定
	void SetRect(const GSrect& rect);

	//貼り付ける四角形の取得
	GSrect GetRect() const;

	//スクリーン座標の設定
	void SetPosition(const GSvector2 position);

	//スクリーン座標の取得
	GSvector2 GetPosition() const;

	//テクスチャの中心座標の設定
	void SetCenter(const GSvector2 center);

	//テクスチャの中心座標の取得
	GSvector2 GetCenter() const;

	//テクスチャの色の設定
	void SetColor(const GScolor& color);

	//テクスチャの色の取得
	GScolor GetColor() const;

	//拡大縮小の設定
	void SetScale(const GSvector2 scale);

	//拡大縮小の取得
	GSvector2 GetScale() const;

	//回転の設定
	void SetRotate(const float rotate);

	//回転の取得
	float GetRotate() const;

private:
	GSrect m_Rect;			//貼り付ける四角形
	GSvector2 m_Position;	//スクリーン座標
	GSvector2 m_Center;		//テクスチャの中心座標
	GScolor m_Color;		//テクスチャの色
	GSvector2 m_Scale;		//拡大縮小
	float m_Rotate;			//回転
};

#endif // !TEXTURE2DPARAMETER_H_
