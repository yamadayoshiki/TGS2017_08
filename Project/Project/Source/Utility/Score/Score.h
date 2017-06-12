#ifndef SCORE_H_
#define SCORE_H_

class Score
{
public:
	//コンストラクタ
	Score();
	//初期化
	void initialze();
	//スコアの加算
	void AddScore(const int score);
	//描画
	void draw()const;

private:
	int m_Score;
};
#endif // !SCORE_H_
