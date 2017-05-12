#include "EnemyCommandStraight.h"

//コンストラクタ
EnemyCommandStraight::EnemyCommandStraight(const EnemyBasePtr& enemy, GSvector2 velocity)
	:EnemyCommandBase(enemy) {
	m_Velocity = velocity;
}

//更新
void EnemyCommandStraight::Update(float deltaTime) {
	//正面に壁があるか検出

}

//終了
void EnemyCommandStraight::Finalize() {

}

//各種固有の初期化
void EnemyCommandStraight::OnInitialize() {

}

//正面に壁があった場合のリアクション
void EnemyCommandStraight::HitWallReaction() {
	TurnBack();
}

//折り返す
void EnemyCommandStraight::TurnBack() {
	m_Velocity = -m_Velocity;
}