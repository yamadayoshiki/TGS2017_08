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
	//スコアの数値を取得
	int ReleaseScore();
	//トータルスコアの取得
	int GetTotalScore();
	//スコアのリセット
	void ScoreRest();
	//座標の設定
	void setPosition(const GSvector2& position);

private:
	int m_Score;
	int m_Total_Score;
	//座標
	GSvector2 m_Position{ 0.0f,0.0f };
};
#endif // !SCORE_H_
