#include "EnemyStateRun.h"

//コンストラクタ
EnemyStateRun::EnemyStateRun(
	const EnemyBasePtr& enemy)
	:EnemyStateMoveBase(enemy) {
}
// 各状態独自の初期化
void EnemyStateRun::onUniqueInit() {

}
// 更新処理
void EnemyStateRun::onUpdate(float deltaTime) {
}