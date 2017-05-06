#include "EnemyCommandStop.h"

//コンストラクタ
EnemyCommandStop::EnemyCommandStop(const EnemyBasePtr& enemy, int stopTimer)
	: EnemyCommandBase(enemy)
	, m_EndTimer(0)
	, m_StopTimer(stopTimer) {
}

//各種固有の初期化
void EnemyCommandStop::OnInitialize() {
	m_EndTimer = 0;
}

//更新
void EnemyCommandStop::Update(float deltaTime) {
	//タイマーの更新
	m_EndTimer++;
}

//終了
void EnemyCommandStop::Finalize() {
}

//終了チェック
bool EnemyCommandStop::IsEnd() {
	//指定の時間が経過した場合終了
	if (m_EndTimer >= m_StopTimer)
		return true;

	return false;
}

//命令ステート
EnemyStateName EnemyCommandStop::GetCurrentStateName() const {
	return EnemyStateName::Idle;
}