#include "Score.h"

#include <gslib.h>
#include <GStype.h>
#include <sstream>
#include <algorithm>

//コンストラクタ
Score::Score()
{
	initialze();
}

//初期化
void Score::initialze()
{
	m_Score = 0;
	m_Position = GSvector2(200, 50);
}

//スコアの加算
void Score::AddScore(const int score)
{
	m_Score += score;
}

int Score::ReleaseScore()
{
	return m_Score;
}

//座標の設定
void Score::setPosition(const GSvector2& position)
{
	m_Position = position;
}

//描画
void Score::draw() const
{
	std::stringstream ss;
	ss << "SCORE " << m_Score;

	// パラメーターの描画
	gsTextPos(m_Position.x + 100, m_Position.y);
	gsFontParameter(GS_FONT_BOLD, 50, "HG明朝B");
	gsDrawText(ss.str().c_str());

	// パラメータを戻す
	gsFontParameter(GS_FONT_BOLD, 20, "HG明朝B");
}
