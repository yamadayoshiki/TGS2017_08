#include "EnemyStateMoveBase.h"
#include "../../../../Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"

// コンストラクタ
EnemyStateMoveBase::EnemyStateMoveBase(const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// 各状態独自の初期化
void EnemyStateMoveBase::unique_init() {
	//継承先の各状態独自の初期化
	onUniqueInit();
}

// 更新処理
void EnemyStateMoveBase::update(float deltaTime) {
	//目的地までのベクトル
	GSvector2 velocity = p_Enemy->GetCommandManager()->GetCommandVector();

	//移動の速度によって状態を変更（待機、動く）
	if (velocity.length() <= 0)
		change(EnemyStateName::Idle);
	else
		change(EnemyStateName::Move);

	//継承先の更新処理
	onUpdate(deltaTime);
}

// 衝突判定
void EnemyStateMoveBase::collide(const Actor & other) {
	// 継承先の衝突判定
	onCollide(other);
}

// 終了時の処理
void EnemyStateMoveBase::end() {
	//継承先の終了処理
	onEnd();
}

// 入力処理
void EnemyStateMoveBase::input() {
	// コマンド指定のState
	EnemyStateName name = p_Enemy->GetCommandManager()->GetCommandState();
	if (name != EnemyStateName::None)
		change(name);

	// 継承先の入力処理
	onInput();
}

// メッセージ処理
void EnemyStateMoveBase::handleMessage(EventMessage message, void* param) {
	switch (message)
	{
		//プレイヤーに挟まれたとき
	case EventMessage::PLAYER_ROUNDS:
		change(EnemyStateName::Caught);
		break;
	}
}