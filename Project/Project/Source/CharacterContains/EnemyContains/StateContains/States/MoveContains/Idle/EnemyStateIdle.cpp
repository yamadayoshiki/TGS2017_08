#include "EnemyStateIdle.h"

//�R���X�g���N�^
EnemyStateIdle::EnemyStateIdle(const EnemyBasePtr& enemy)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBase(enemy){
}

//�e��ԌŗL�̏�����
void EnemyStateIdle::onUniqueInit()
{
	//�A�j���[�V�����̕ύX

}