#include "EnemyStateMoveRepelMove.h"

EnemyStateMoveRepelMove::EnemyStateMoveRepelMove(const EnemyBasePtr & enemy, const float speed)
	:EnemyStateMoveRepelBase(enemy)
	, m_Speed(speed) {
}

void EnemyStateMoveRepelMove::onUniqueInit()
{
}

void EnemyStateMoveRepelMove::onUpdate(float deltaTime) {
	//�ړ�����
	Move(deltaTime, m_Speed);
}
