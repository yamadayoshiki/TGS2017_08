#include "EnemyStateManager.h"
#include "../States/EnemyStateName.h"

// �f�t�H���g�R���X�g���N�^
EnemyStateManager::EnemyStateManager() {
}

EnemyStateName EnemyStateManager::GetCurStateName() const{
	return (EnemyStateName)m_CurrentID;
}
