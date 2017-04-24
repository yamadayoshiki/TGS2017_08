#include "Enemy_Command_Approach_FixedDistance.h"

//コンストラクタ
Enemy_Command_Approach_FixedDistance::Enemy_Command_Approach_FixedDistance()
	:Enemy_Command_Base() {
}

//更新
void Enemy_Command_Approach_FixedDistance::Update() {

}

//終了
void Enemy_Command_Approach_FixedDistance::Finalize() {
	delete p_TargetPos;
}

//命令ステート
EnemyStateName Enemy_Command_Approach_FixedDistance::GetCurrentStateName() {
	return EnemyStateName::Move;
}

//目標座標の指定
void Enemy_Command_Approach_FixedDistance::SetTargetPos(GSvector2* targetPos) {

}

//各種固有の初期化
void Enemy_Command_Approach_FixedDistance::OnInitialize() {

}