#include "Enemy_Command_Approach_FixedDistance.h"

//コンストラクタ
Enemy_Command_Approach_FixedDistance::Enemy_Command_Approach_FixedDistance(float fixedDistance)
	: Enemy_Command_Base()
	, m_TargetPos(GSvector2(0.0f, 0.0f))
	, m_FixedDistance(fixedDistance) {
}

//更新
void Enemy_Command_Approach_FixedDistance::Update() {

}

//終了
void Enemy_Command_Approach_FixedDistance::Finalize() {
}

//命令ステート
EnemyStateName Enemy_Command_Approach_FixedDistance::GetCurrentStateName() {
	return EnemyStateName::Move;
}

//目標座標の指定
void Enemy_Command_Approach_FixedDistance::SetTargetPos(const GSvector2& targetPos) {
	m_TargetPos = targetPos;
}

//各種固有の初期化
void Enemy_Command_Approach_FixedDistance::OnInitialize() {

}