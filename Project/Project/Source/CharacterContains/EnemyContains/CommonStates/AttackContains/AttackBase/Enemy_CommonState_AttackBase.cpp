#include "Enemy_CommonState_AttackBase.h"

// コンストラクタ
Enemy_CommonState_AttackBase::Enemy_CommonState_AttackBase(GSvector2& pos, GSmatrix4& mat)
	:Enemy_BaseState(pos, mat) {
}

// 各状態独自の初期化
void Enemy_CommonState_AttackBase::unique_init(Actor & actor) {
	// 継承先の各状態独自の初期化
	onUniqueInit(actor);
}

// 更新処理
void Enemy_CommonState_AttackBase::update(Actor & actor, float deltaTime) {
	//アニメーションが終了した場合IDLEに遷移


	//継承先の更新処理
	onUpdate(actor, deltaTime);
}

// 衝突判定
void Enemy_CommonState_AttackBase::collide(const Actor & other) {
	// 継承先の衝突判定
	onCollide(other);
}

// 終了時の処理
void Enemy_CommonState_AttackBase::end() {
	//継承先の終了処理
	onEnd();
}

// 入力処理
void Enemy_CommonState_AttackBase::input() {
	//継承先の入力処理
	onInput();
}