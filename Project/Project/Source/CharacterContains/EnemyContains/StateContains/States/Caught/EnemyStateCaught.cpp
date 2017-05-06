#include "EnemyStateCaught.h"

//コンストラクタ
EnemyStateCaught::EnemyStateCaught(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// 各状態独自の初期化
void EnemyStateCaught::unique_init() {
}

// 更新処理
void EnemyStateCaught::update(float deltaTime) {
}

// 衝突判定
void EnemyStateCaught::collide(const Actor & other) {

}

// 終了時の処理
void EnemyStateCaught::end() {
}