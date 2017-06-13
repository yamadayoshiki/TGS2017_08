#ifndef SCORE_H_
#define SCORE_H_

#include<gslib.h>

class Score
{
public:
	//コンストラクタ
	Score();
	//初期化
	void initialze();
	//スコアの加算
	void AddScore(const int score);
	//座標の設定
	void setPosition(const GSvector2& position);
	//描画
	void draw()const;

private:
	int m_Score;
	//座標
	GSvector2 m_Position{0.0f,0.0f};
};
#endif // !SCORE_H_
