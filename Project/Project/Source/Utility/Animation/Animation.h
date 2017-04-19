#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <gslib.h>

class Animation
{
public:
	//コンストラクタ
	Animation(
		const GSrect& texRect,
		const float cutWidth,
		const unsigned int animmationUpdateTimer);
	//デフォルトコンストラクタ
	Animation();
	//デストラクタ
	~Animation();
	//初期化
	void Initialize();
	//更新
	void Update(float deltaTime);
	//描画矩形変更
	void Change(unsigned int num);
	//描画矩形の取得
	GSrect* GetCurrentRect();

private:
	//テクスチャ矩形
	GSrect m_TexRect;
	//切り取る矩形の横幅
	float m_CutWidth;
	//テクスチャ変更間隔(フレーム)
	unsigned int m_AnimationUpdateTimer;
	//切り取る矩形
	GSrect m_CutRect;
	//切り取る番号(0枚目から数える)
	int m_CurrentNum;
	//アニメーションタイマー
	unsigned int m_AnimationTimer;
};

#endif // !ANIMATION_H_
