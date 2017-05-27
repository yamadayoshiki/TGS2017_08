#include "EnemyStateStop.h"

EnemyStateStop::EnemyStateStop(const EnemyBasePtr & enemy, int limitTimer)
	: EnemyStateBase(enemy)
	, m_LimitTimer(limitTimer)
	, m_Timer(0) {
}

void EnemyStateStop::unique_init() {
	m_Timer = 0;
}

void EnemyStateStop::update(float deltaTime) {
	m_Timer++;
	if (m_LimitTimer <= m_Timer)
		change(EnemyStateName::Idle);
}