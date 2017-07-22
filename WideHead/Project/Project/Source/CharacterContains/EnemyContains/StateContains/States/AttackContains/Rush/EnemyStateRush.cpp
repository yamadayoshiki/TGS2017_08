#include "EnemyStateRush.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"

EnemyStateRush::EnemyStateRush(const EnemyBasePtr & enemy, const float speed)
	: EnemyStateBase(enemy)
	, m_Speed(speed) {
}

void EnemyStateRush::unique_init() {
	//テクスチャ切替
	p_Enemy.lock()->Settexture("Rush");
}

void EnemyStateRush::update(float deltaTime) {
	//注視あり移動
	RegardMove(p_Enemy.lock()->GetDirection(), deltaTime, m_Speed);
}

void EnemyStateRush::end() {
	//テクスチャ切替
	p_Enemy.lock()->Settexture("Normal");
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