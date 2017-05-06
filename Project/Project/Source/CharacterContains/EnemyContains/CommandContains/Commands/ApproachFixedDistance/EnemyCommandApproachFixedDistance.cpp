#include "EnemyCommandApproachFixedDistance.h"

//コンストラクタ
EnemyCommandApproachFixedDistance::EnemyCommandApproachFixedDistance(const EnemyBasePtr& enemy, float fixedDistance)
	: EnemyCommandBase(enemy)
	, m_TargetPos(GSvector2(0.0f, 0.0f))
	, m_FixedDistance(fixedDistance) {
}

//各種固有の初期化
void EnemyCommandApproachFixedDistance::OnInitialize() {

}

//更新
void EnemyCommandApproachFixedDistance::Update(float deltaTime) {

}

//終了
void EnemyCommandApproachFixedDistance::Finalize() {
}

//終了チェック
bool EnemyCommandApproachFixedDistance::IsEnd() {
	return false;
}

//命令ステート
EnemyStateName EnemyCommandApproachFixedDistance::GetCurrentStateName() const {
	return EnemyStateName::Move;
}

//目標座標の指定
void EnemyCommandApproachFixedDistance::SetTargetPos(const GSvector2& targetPos) {
	m_TargetPos = targetPos;
}

//近づく距離の設定
void EnemyCommandApproachFixedDistance::SetFixedDistance(float fixedDistance) {
	m_FixedDistance = fixedDistance;
}