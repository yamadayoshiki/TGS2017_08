#include "EnemyStateWalk.h"

//コンストラクタ
EnemyStateWalk::EnemyStateWalk(const EnemyBasePtr& enemy)
	:EnemyStateMoveBase(enemy) {
}

// 各状態独自の初期化
void EnemyStateWalk::onUniqueInit() {
	//モーション変更

}

// 更新処理
void EnemyStateWalk::onUpdate(float deltaTime) {
	Move(deltaTime, 1.0f);
}