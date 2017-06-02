#include "EnemyStateRepel.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../WorldContains/EventMessage/EventMessage.h"

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

// 衝突判定
void EnemyStateRepel::collide(const Actor & other) {
}

// 終了時の処理
void EnemyStateRepel::end() {
}