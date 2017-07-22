#include "EnemyStateMoveBaseStandard.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"

// コンストラクタ
EnemyStateMoveBaseStandard::EnemyStateMoveBaseStandard(const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// 各状態独自の初期化
void EnemyStateMoveBaseStandard::unique_init() {
	//継承先の各状態独自の初期化
	onUniqueInit();
}

// 更新処理
void EnemyStateMoveBaseStandard::update(float deltaTime) {
	//目的地までのベクトル
	GSvector2 velocity = p_Enemy.lock()->GetCommandManager()->GetCommandVector();

	//移動の速度によって状態を変更（待機、動く）
	if (velocity.length() <= 0)
		change(EnemyStateName::Idle);
	else
		change(EnemyStateName::Move);

	//継承先の更新処理
	onUpdate(deltaTime);
}

// 衝突判定
void EnemyStateMoveBaseStandard::collide(const Actor & other, const Body::ContactSet& contactSet) {
	// 継承先の衝突判定
	onCollide(other, contactSet);
}

// 終了時の処理
void EnemyStateMoveBaseStandard::end() {
	//継承先の終了処理
	onEnd();
}

// 入力処理
void EnemyStateMoveBaseStandard::input() {
	// コマンド指定のState
	EnemyStateName name = p_Enemy.lock()->GetCommandManager()->GetCommandState();
	if (name != EnemyStateName::None)
		change(name);

	// 継承先の入力処理
	onInput();
}

// メッセージ処理
void EnemyStateMoveBaseStandard::OnHandleMessage(EventMessage message, void* param) {
	switch (message)
	{
		//プレイヤーに挟まれたとき
	case EventMessage::PLAYER_ROUNDS:
		change(EnemyStateName::Caught);
		break;
	}
}