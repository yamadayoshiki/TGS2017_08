#include "Enemy_CommonState_MoveBase.h"

// コンストラクタ
Enemy_CommonState_MoveBase::Enemy_CommonState_MoveBase(GSvector2& pos, GSmatrix4& mat)
	:Enemy_BaseState(pos, mat)
{
}

// 各状態独自の初期化
void Enemy_CommonState_MoveBase::unique_init(Actor & actor)
{
	//継承先の各状態独自の初期化
	onUniqueInit(actor);
}

// 更新処理
void Enemy_CommonState_MoveBase::update(Actor & actor, float deltaTime)
{
	//移動の速度によって状態を変更（待機、歩く、走る）

	//継承先の更新処理
	onUpdate(actor, deltaTime);
}

// 衝突判定(未実装)
void Enemy_CommonState_MoveBase::collide(const Actor & other)
{
	/* 攻撃等に対するリアクション */
	if (other.getName() == ActorName::None) {
		change(EnemyStateName::None);
	}

	// 継承先の衝突判定
	onCollide(other);
}

// 終了時の処理
void Enemy_CommonState_MoveBase::end()
{
	//継承先の終了処理
	onEnd();
}