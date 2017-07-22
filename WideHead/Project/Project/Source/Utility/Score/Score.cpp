#include "Score.h"

#include <gslib.h>
#include <GStype.h>
#include <sstream>
#include <algorithm>
#include"../../Base/GameManagerContains/GameManager/GameManager.h"
#include"../Rederer2D/Renderer2D.h"
#include"../Texture2DParameter/Texture2DParameter.h"


//コンストラクタ
Score::Score() {
	initialze();
}

//初期化
void Score::initialze() {
	m_Score = 0;
	m_Total_Score = 0;
	m_Position = GSvector2(200, 50);
}

//スコアの加算
void Score::AddScore(const int score) {
	m_Score = std::min(m_Score + score, 99999);
	m_Total_Score = std::min(m_Total_Score + score, 99999);
}

int Score::ReleaseScore() {
	return m_Score;
}

//トータルスコアの取得
int Score::GetTotalScore() {
	return m_Total_Score;
}

//スコアのリセット
void Score::ScoreRest() {
	m_Score = 0;
}

//座標の設定
void Score::setPosition(const GSvector2& position) {
	m_Position = position;
}