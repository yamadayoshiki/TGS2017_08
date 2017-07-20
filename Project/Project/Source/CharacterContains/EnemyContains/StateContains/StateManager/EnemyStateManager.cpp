#include "EnemyStateManager.h"
#include "../States/EnemyStateName.h"

// デフォルトコンストラクタ
EnemyStateManager::EnemyStateManager() {
}

EnemyStateName EnemyStateManager::GetCurStateName() const{
	return (EnemyStateName)m_CurrentID;
}
