#include "EnemyStateMoveRepelMove.h"
#include "../../../../Enemys/Base/EnemyBase.h"
#include "../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"

EnemyStateMoveRepelMove::EnemyStateMoveRepelMove(const EnemyBasePtr & enemy, const float speed)
	:EnemyStateMoveRepelBase(enemy)
	, m_Speed(speed) {
}

void EnemyStateMoveRepelMove::onUniqueInit()
{
}

void EnemyStateMoveRepelMove::onUpdate(float deltaTime) {
	if (p_Enemy->GetCommandManager()->IsRegard() == false)
		ForwardMove(deltaTime, m_Speed);

	else
		RegardMove(p_Enemy->GetDirection(),deltaTime, m_Speed);
}