#include "EnemyStateEnemy02Dead.h"
#include "../../../../Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

// コンストラクタ
EnemyStateEnemy02Dead::EnemyStateEnemy02Dead(const EnemyBasePtr & enemy)
	:EnemyStateDead(enemy)
{
}

// 各種固有の初期化
void EnemyStateEnemy02Dead::unique_init() {
	p_Enemy.lock()->getWorld()->sendMessage(EventMessage::ENEMY02_DEAD);
}
