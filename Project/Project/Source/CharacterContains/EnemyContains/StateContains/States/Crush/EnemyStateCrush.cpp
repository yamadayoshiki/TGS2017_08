#include "EnemyStateCrush.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../WorldContains/EventMessage/EventMessage.h"


//コンストラクタ
EnemyStateCrush::EnemyStateCrush(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// 各状態独自の初期化
void EnemyStateCrush::unique_init() {
	//モーションの変更

	//ダメージを受ける
	p_Enemy.lock()->GetHitPoint().Decrease(1);
}

// 更新処理
void EnemyStateCrush::update(float deltaTime) {
	if (p_Enemy.lock()->GetHitPoint().IsDead() == true)
		change(EnemyStateName::Dead);

	else
		change(EnemyStateName::Caught);
}

// 衝突判定
void EnemyStateCrush::collide(const Actor & other) {
}

// 終了時の処理
void EnemyStateCrush::end() {
}

