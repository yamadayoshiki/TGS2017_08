#include "EnemyStateRepel.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

//コンストラクタ
EnemyStateRepel::EnemyStateRepel(const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}
// 各状態独自の初期化
void EnemyStateRepel::unique_init() {
	//弾く
	p_Enemy.lock()->getWorld()->sendMessage(EventMessage::ENEMY_REPEL);
}

// 更新処理
void EnemyStateRepel::update(float deltaTime) {
	change(EnemyStateName::Idle);
}