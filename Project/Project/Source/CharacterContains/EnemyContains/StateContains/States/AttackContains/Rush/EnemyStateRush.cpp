#include "EnemyStateRush.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

EnemyStateRush::EnemyStateRush(const EnemyBasePtr & enemy, const float speed)
	: EnemyStateBase(enemy)
	, m_Speed(speed) {
}

void EnemyStateRush::update(float deltaTime) {
	//注視あり移動
	RegardMove(p_Enemy.lock()->GetDirection(), deltaTime, m_Speed);
}

void EnemyStateRush::OnHandleMessage(EventMessage message, void * param) {
	switch (message)
	{
		//プレイヤーに挟まれたとき
	case EventMessage::PLAYER_ROUNDS:
		change(EnemyStateName::Repel);
		break;

		//壁に刺さって終了
	case EventMessage::ENEMY_STATEEND:
		change(EnemyStateName::StickWall);
		break;
	}
}