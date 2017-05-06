#include "EnemyStateManager.h"
#include "../States/EnemyStateName.h"

// デフォルトコンストラクタ
EnemyStateManager::EnemyStateManager()
	:EnemyStateManager(nullptr) {
}

// コンストラクタ
EnemyStateManager::EnemyStateManager(const EnemyBasePtr& enemy) {
	//初期ステートを設定
	change(EnemyStateName::Idle);
}