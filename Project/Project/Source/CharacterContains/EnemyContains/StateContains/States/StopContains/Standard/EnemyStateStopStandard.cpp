#include "EnemyStateStopStandard.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

EnemyStateStopStandard::EnemyStateStopStandard(const EnemyBasePtr& enemy, float limitTimer)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBaseStandard(enemy)
	, m_LimitTimer(limitTimer)
	, m_Timer(0.0f) {
}

void EnemyStateStopStandard::unique_init() {
	m_Timer = 0;
}

void EnemyStateStopStandard::update(float deltaTime) {
	m_Timer = m_Timer + deltaTime;
	if (m_LimitTimer <= m_Timer)
		change(EnemyStateName::Idle);
}

//メッセージ処理
void EnemyStateStopStandard::OnHandleMessage(EventMessage message, void * param){
	EnemyStateMoveBaseStandard::OnHandleMessage(message, param);
	switch (message)
	{
	case EventMessage::ENEMY_STATEEND:
		change(EnemyStateName::Idle);
		break;
	}
}