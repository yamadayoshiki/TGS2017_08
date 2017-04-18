#include "State.h"

// コンストラクタ
State::State() :
	m_ID(-1),
	m_NextID(-1),
	m_Timer(0), m_IsEnd(false) {}

// 全状態共通の初期化
void State::common_init(Actor & actor, const int id) {
	// 変数の初期化
	m_ID = id;
	m_Timer = 0;
	m_IsEnd = false;
}

// 入力処理
void State::input() {}

// 時間管理
void State::timer(const float& deltaTime) {
	m_Timer += deltaTime;
}

// ステートの変更処理
void State::change_int(const int id)
{
	change(id);
}

// ステートが終了したか否か
bool State::isEnd() {
	return m_IsEnd;
}

// 次のステートの要素
int State::next() const {
	return m_NextID;
}


