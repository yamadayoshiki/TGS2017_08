#include "EnemyStateMove.h"

//�R���X�g���N�^
EnemyStateMove::EnemyStateMove(const EnemyBasePtr& enemy)
	:EnemyStateMoveBase(enemy)
{
}

//�e��ԌŗL�̏�����
void EnemyStateMove::onUniqueInit()
{
	//�A�j���[�V�����̕ύX

}

// �X�V����
void EnemyStateMove::onUpdate(float deltaTime) {
	//�ړ�����
	Move(deltaTime, 1.0f);
}