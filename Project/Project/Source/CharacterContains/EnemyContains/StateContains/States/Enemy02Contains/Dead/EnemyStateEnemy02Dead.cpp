#include "EnemyStateEnemy02Dead.h"
#include "../../../../Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

// �R���X�g���N�^
EnemyStateEnemy02Dead::EnemyStateEnemy02Dead(const EnemyBasePtr & enemy)
	:EnemyStateDead(enemy)
{
}

// �e��ŗL�̏�����
void EnemyStateEnemy02Dead::unique_init() {
	p_Enemy.lock()->getWorld()->sendMessage(EventMessage::ENEMY02_DEAD);
}
