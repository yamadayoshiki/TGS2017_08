#include "EnemyStateIdleStandard.h"

//�R���X�g���N�^
EnemyStateIdleStandard::EnemyStateIdleStandard(const EnemyBasePtr& enemy)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBaseStandard(enemy){
}

//�e��ԌŗL�̏�����
void EnemyStateIdleStandard::onUniqueInit()
{
	//�A�j���[�V�����̕ύX

}