#include "EnemyCommandLeaveFixedDistance.h"

//コンストラクタ
EnemyCommandLeaveFixedDistance::EnemyCommandLeaveFixedDistance(const EnemyBasePtr& enemy, float fixedDistance)
	:EnemyCommandBase(enemy) {

}

//各種固有の初期化
void EnemyCommandLeaveFixedDistance::OnInitialize() {

}

//更新
void EnemyCommandLeaveFixedDistance::Update(float deltaTime) {

}

//終了
void EnemyCommandLeaveFixedDistance::Finalize() {

}

//終了チェック
bool EnemyCommandLeaveFixedDistance::IsEnd() {
	return false;
}

//命令ステート
EnemyStateName EnemyCommandLeaveFixedDistance::GetCurrentStateName() const {
	return EnemyStateName::Move;
}

//目標座標の設定
void EnemyCommandLeaveFixedDistance::SetTargetPos(const GSvector2& targetPos) {
	m_TargetPos = targetPos;
}

//離れる距離の設定
void EnemyCommandLeaveFixedDistance::SetFixedDistance(const float fixedDistance) {
	m_FixedDistance = fixedDistance;
}