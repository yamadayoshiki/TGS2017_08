#include "EnemyStateManager.h"
#include "../States/EnemyStateName.h"

// �f�t�H���g�R���X�g���N�^
EnemyStateManager::EnemyStateManager()
	:EnemyStateManager(nullptr) {
}

// �R���X�g���N�^
EnemyStateManager::EnemyStateManager(const EnemyBasePtr& enemy) {
	//�����X�e�[�g��ݒ�
	change(EnemyStateName::Idle);
}