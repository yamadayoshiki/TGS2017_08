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
}

//スコアの加算
void Score::AddScore(const int score)
{
	m_Score += score;
}

//描画
void Score::draw() const
{
	std::stringstream ss;
	ss << "SCORE " << m_Score;
	// 画像の描画
	GSvector2 pos = GSvector2(200, 50);

	// パラメーターの描画
	gsTextPos(pos.x + 100, pos.y);
	gsFontParameter(GS_FONT_BOLD, 50, "HG明朝B");
	gsDrawText(ss.str().c_str());

	// パラメータを戻す
	gsFontParameter(GS_FONT_BOLD, 20, "HG明朝B");
}
