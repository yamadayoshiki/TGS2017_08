#include "EnemyCommandEnemy07Spin.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../StateContains/StateManager/EnemyStateManager.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../NeutralContains/Explosion/Neutral_Explosion.h"
#include "../../../../../../ActorContains/ActorGroup.h"

EnemyCommandEnemy07Spin::EnemyCommandEnemy07Spin(const EnemyBasePtr & enemy, const int limitSpringCounter)
	: EnemyCommandStraight(enemy, MapType::Double)
	, m_SpringCounter(0)
	, m_LimitSpringCounter(limitSpringCounter) {
}

void EnemyCommandEnemy07Spin::HitWallReaction() {
	//•Ç‚É“–‚½‚Á‚½‰ñ”ŒvŽZ
	m_SpringCounter++;
	if (m_SpringCounter > m_LimitSpringCounter)
	{
		p_Enemy.lock()->GetStateManager()->handleMessage(EventMessage::ENEMY_COMMAND_DEAD, nullptr);
		p_Enemy.lock()->getWorld()->addActor(ActorGroup::Effect, std::make_shared<Neutral_Explosion>(p_Enemy.lock()->getWorld(), p_Enemy.lock()->getPosition(), p_Enemy.lock()->GetGameMgr()));
		//gsPlaySE()
	}
	EnemyCommandStraight::HitWallReaction();
}