#include "EnemyStateWalk.h"

//�R���X�g���N�^
EnemyStateWalk::EnemyStateWalk(const EnemyBasePtr& enemy)
	:EnemyStateMoveBase(enemy) {
}

// �e��ԓƎ��̏�����
void EnemyStateWalk::onUniqueInit() {
	//���[�V�����ύX

}

// �X�V����
void EnemyStateWalk::onUpdate(float deltaTime) {
	Move(deltaTime, 1.0f);
}