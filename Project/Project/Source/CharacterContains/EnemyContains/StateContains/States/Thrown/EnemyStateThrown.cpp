#include "EnemyStateThrown.h"

//コンストラクタ
EnemyStateThrown::EnemyStateThrown(const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}
// 各状態独自の初期化
void EnemyStateThrown::unique_init() {
}
// 更新処理
void EnemyStateThrown::update(float deltaTime) {
}
// 衝突判定
void EnemyStateThrown::collide(const Actor & other) {}
// 終了時の処理
void EnemyStateThrown::end() {
}