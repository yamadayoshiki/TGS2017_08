#include "EnemyStateMoveBase.h"

// コンストラクタ
EnemyStateMoveBase::EnemyStateMoveBase(const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy)
{
}

// 各状態独自の初期化
void EnemyStateMoveBase::unique_init()
{
	//継承先の各状態独自の初期化
	onUniqueInit();
}

// 更新処理
void EnemyStateMoveBase::update(float deltaTime)
{
	//移動の速度によって状態を変更（待機、歩く、走る）


	//継承先の更新処理
	onUpdate(deltaTime);
}

// 衝突判定(未実装)
void EnemyStateMoveBase::collide(const Actor & other)
{
	/* 攻撃等に対するリアクション */
	if (other.getName() == ActorName::None) {
		change(EnemyStateName::None);
	}

	// 継承先の衝突判定
	onCollide(other);
}

// 終了時の処理
void EnemyStateMoveBase::end()
{
	//継承先の終了処理
	onEnd();
}

// 入力処理
void EnemyStateMoveBase::input() {
	//命令に応じた行動

	// 継承先の入力処理
	onInput();
}