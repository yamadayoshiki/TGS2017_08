#ifndef SCORE_H_
#define SCORE_H_

#include<gslib.h>
#include"../Rederer2D/Renderer2DPtr.h"

class Score
{
public:
	//コンストラクタ
	Score();
	//初期化
	void initialze();
	//スコアの加算
	void AddScore(const int score);
	//スコアの数値を渡す
	int ReleaseScore();
	//座標の設定
	void setPosition(const GSvector2& position);
	//描画
	void draw(Renderer2DPtr& renderer)const;

private:
	int m_Score;
	//座標
	GSvector2 m_Position{0.0f,0.0f};
};
#endif // !SCORE_H_
