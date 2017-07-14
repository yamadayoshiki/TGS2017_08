#include "EnemyStateAttackBase.h"

// コンストラクタ
EnemyStateAttackBase::EnemyStateAttackBase(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// 各状態独自の初期化
void EnemyStateAttackBase::unique_init() {
	// 継承先の各状態独自の初期化
	onUniqueInit();
}

// 更新処理
void EnemyStateAttackBase::update(float deltaTime) {
	//アニメーションが終了した場合IDLEに遷移


	//継承先の更新処理
	onUpdate(deltaTime);
}

// 衝突判定
void EnemyStateAttackBase::collide(const Actor & other, const Body::ContactSet& contactSet) {
	// 継承先の衝突判定
	onCollide(other, contactSet);
}

// 終了時の処理
void EnemyStateAttackBase::end() {
	//継承先の終了処理
	onEnd();
}

// 入力処理
void EnemyStateAttackBase::input() {
	//継承先の入力処理
	onInput();
}