#include "EnemyStateDead.h"
#include "../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../WorldContains/EventMessage/EventMessage.h"

//コンストラクタ
EnemyStateDead::EnemyStateDead(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {

}
// 各状態独自の初期化
void EnemyStateDead::unique_init() {
	p_Enemy.lock()->getWorld()->sendMessage(EventMessage::PLAYER_ROUNDSLOST);

	//アニメーションの変更

}

// 更新処理
void EnemyStateDead::update(float deltaTime) {
	//アニメーションが終了したらActorから削除
	p_Enemy.lock()->dead();
}

// 衝突判定
void EnemyStateDead::collide(const Actor & other) {

}

// 終了時の処理
void EnemyStateDead::end() {

}