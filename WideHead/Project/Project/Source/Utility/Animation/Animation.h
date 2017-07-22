#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <gslib.h>
#include "AnimationPtr.h"
class Animation
{
public:
	//コンストラクタ
	Animation(
		const GSrect& texRect,
		const float cutWidth,
		const float animmationUpdateTimer);

	//デフォルトコンストラクタ
	Animation();
	//デストラクタ
	~Animation();
	//初期化
	void Initialize();
	//更新
	void Update(float deltaTime);
	//描画矩形変更
	void Change();
	//描画矩形の取得
	GSrect* GetCurrentRect();
	//ループ回数の取得
	unsigned int GetLoopCount();
	//クローン生成
	AnimationSPtr Clone();
	//切り取る矩形の横幅の取得
	float GetCutWidth() const;

private:
	GSrect m_TexRect;						//テクスチャ矩形
	float m_CutWidth;						//切り取る矩形の横幅
	float m_AnimationUpdateTimer;			//テクスチャ変更間隔(フレーム)
	GSrect m_CutRect;						//切り取る矩形
	int m_CurrentNum;						//切り取る番号("0"枚目から数える)
	float m_AnimationTimer;					//アニメーションタイマー
	unsigned int m_LoopCount;				//ループ回数
};

#endif // !ANIMATION_H_
