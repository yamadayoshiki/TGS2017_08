#include "EnemyCommandEnemy07Spin.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../StateContains/StateManager/EnemyStateManager.h"

EnemyCommandEnemy07Spin::EnemyCommandEnemy07Spin(const EnemyBasePtr & enemy, const int limitSpringCounter)
	: EnemyCommandStraight(enemy, MapType::Double) {
}

void EnemyCommandEnemy07Spin::HitWallReaction() {
	//壁に当たった回数計算
	m_SpringCounter++;
	if (m_SpringCounter > m_LimitSpringCounter)
	{
		p_Enemy.lock()->GetStateManager()->handleMessage(EventMessage::ENEMY_COMMAND_DEAD, nullptr);
	//gsPlaySE()
	}
	EnemyCommandStraight::HitWallReaction();
}