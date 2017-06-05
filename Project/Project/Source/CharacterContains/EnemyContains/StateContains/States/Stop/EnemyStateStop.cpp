#include "EnemyStateStop.h"

EnemyStateStop::EnemyStateStop(const EnemyBasePtr & enemy, float limitTimer)
	: EnemyStateBase(enemy)
	, m_LimitTimer(limitTimer)
	, m_Timer(0.0f) {
}

void EnemyStateStop::unique_init() {
	m_Timer = 0;
}

void EnemyStateStop::update(float deltaTime) {
	m_Timer = m_Timer + deltaTime;
	if (m_LimitTimer <= m_Timer)
		change(EnemyStateName::Idle);
}