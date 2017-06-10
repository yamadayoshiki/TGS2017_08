#include "EnemyStateDeadStandard.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"

//コンストラクタ
EnemyStateDeadStandard::EnemyStateDeadStandard(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {

}
// 各状態独自の初期化
void EnemyStateDeadStandard::unique_init() {
	p_Enemy.lock()->getWorld()->sendMessage(EventMessage::PLAYER_ROUNDSLOST);

	//アニメーションの変更

}

// 更新処理
void EnemyStateDeadStandard::update(float deltaTime) {
	//アニメーションが終了したらActorから削除
	p_Enemy.lock()->dead();
}

// 衝突判定
void EnemyStateDeadStandard::collide(const Actor & other) {

}

// 終了時の処理
void EnemyStateDeadStandard::end() {

}