#include "EnemyStateRushPreliminary.h"

//コンストラクタ
EnemyStateRushPreliminary::EnemyStateRushPreliminary(
	const EnemyBasePtr& enemy)
	:EnemyStateAttackBase(enemy){
}

// 各状態独自の初期化
void EnemyStateRushPreliminary::onUniqueInit() {}
// 更新
void EnemyStateRushPreliminary::onUpdate(float deltaTime){}
// 衝突判定
void EnemyStateRushPreliminary::onCollide(const Actor & other) {}
// 終了時の処理
void EnemyStateRushPreliminary::onEnd() {}
// 入力処理
void EnemyStateRushPreliminary::onInput() {}