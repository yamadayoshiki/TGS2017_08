#include "EnemyStateRush.h"

// コンストラクタ
EnemyStateRush::EnemyStateRush(const EnemyBasePtr& enemy)
	:EnemyStateAttackBase(enemy) {
}

// 各状態独自の初期化
void EnemyStateRush::onUniqueInit() {

}

// 更新処理
void EnemyStateRush::onUpdate(float deltaTime) {

}
// 衝突判定
void EnemyStateRush::onCollide(const Actor & other) {

}
// 終了時の処理
void EnemyStateRush::onEnd() {

}
// 入力処理
void EnemyStateRush::onInput() {

}