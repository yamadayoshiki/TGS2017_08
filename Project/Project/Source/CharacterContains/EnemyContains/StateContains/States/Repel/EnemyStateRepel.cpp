#include "EnemyStateRepel.h"

//コンストラクタ
EnemyStateRepel::EnemyStateRepel(const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}
// 各状態独自の初期化
void EnemyStateRepel::unique_init() {
}
// 更新処理
void EnemyStateRepel::update(float deltaTime) {
}
// 衝突判定
void EnemyStateRepel::collide(const Actor & other) {
}
// 終了時の処理
void EnemyStateRepel::end() {
}