#include "EnemyStateShot.h"

//コンストラクタ
EnemyStateShot::EnemyStateShot(const EnemyBasePtr& enemy)
	:EnemyStateAttackBase(enemy) {
}
// 各状態独自の初期化
void EnemyStateShot::onUniqueInit() {

}
// 更新処理
void EnemyStateShot::onUpdate(float deltaTime) {

}
// 衝突判定
void EnemyStateShot::onCollide(const Actor & other) {

}
// 終了時の処理
void EnemyStateShot::onEnd() {

}
// 入力処理
void EnemyStateShot::onInput() {

}