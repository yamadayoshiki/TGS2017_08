#include "EnemyStateDamage.h"
#include "../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../Utility/Sound/SoundName.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../ActorContains/ActorGroup.h"
#include "../../../../NeutralContains/Explosion/Neutral_Explosion.h"
EnemyStateDamage::EnemyStateDamage(const EnemyBasePtr& enemy,const int damage)
	: EnemyStateBase(enemy)
, m_Damage(damage){
}

void EnemyStateDamage::unique_init() {
	gsPlaySE(SE_PLAYER_EXPLOSION);
	p_Enemy.lock()->GetHitPoint().Decrease(m_Damage);
	p_Enemy.lock()->getWorld()->addActor(ActorGroup::Effect, p_Explosion = std::make_shared<Neutral_Explosion>(p_Enemy.lock()->getWorld(), p_Enemy.lock()->getPosition(), p_Enemy.lock()->GetGameMgr()));
}

void EnemyStateDamage::update(float deltaTime) {
	if (p_Explosion->GetDead() == false)
		return;

	if (p_Enemy.lock()->GetHitPoint().IsDead() == true)
		change(EnemyStateName::Dead);

	else
		change(EnemyStateName::Idle);
}

void EnemyStateDamage::end(){
	p_Explosion.reset();
}
