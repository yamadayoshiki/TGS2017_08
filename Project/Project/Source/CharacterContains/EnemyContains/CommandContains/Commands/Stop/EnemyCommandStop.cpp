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