#include "EnemyCommandLeaveFixedDistance.h"

//コンストラクタ
EnemyCommandLeaveFixedDistance::EnemyCommandLeaveFixedDistance(const EnemyBasePtr& enemy, float fixedDistance)
	: EnemyCommandBase(enemy)
	, m_FixedDistance(fixedDistance) {

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

//命令ステート
EnemyStateName EnemyCommandLeaveFixedDistance::GetCurrentStateName() const {
	return EnemyStateName::None;
}

//目標座標の設定
void EnemyCommandLeaveFixedDistance::SetTargetPos(const GSvector2& targetPos) {
	m_NextTargetPos = targetPos;
}

//離れる距離の設定
void EnemyCommandLeaveFixedDistance::SetFixedDistance(const float fixedDistance) {
	m_FixedDistance = fixedDistance;
}