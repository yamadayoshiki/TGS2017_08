#include "EnemyStateEnemy02Move.h"
#include "../../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"
#include "../../../../../Enemys/Base/EnemyBase.h"

EnemyStateEnemy02Move::EnemyStateEnemy02Move(const EnemyBasePtr & enemy, const float speed)
	: EnemyStateEnemy02MoveBase(enemy)
	, m_Speed(speed) {
}

void EnemyStateEnemy02Move::onUniqueInit() {

}

void EnemyStateEnemy02Move::onUpdate(float deltaTime) {
	if (p_Enemy->GetCommandManager()->IsRegard() == false)
		ForwardMove(deltaTime, m_Speed);

	else
		RegardMove(p_Enemy->GetDirection(), deltaTime, m_Speed);
}