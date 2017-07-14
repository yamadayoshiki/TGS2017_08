#include "EnemyStateCaughtStandard.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../PlayerContains/PlayerState/PlayerStateName.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../../ActorContains/Transform/Transform.h"

//コンストラクタ
EnemyStateCaughtStandard::EnemyStateCaughtStandard(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// 各状態独自の初期化
void EnemyStateCaughtStandard::unique_init() {
	// プレイヤーの取得
	ActorPtr player = p_Enemy.lock()->getWorld()->findActor(ActorName::Player);
	// プレイヤーの座標+前方
	p_Enemy.lock()->setPosition(player->getPosition() + player->getTransform()->GetForward()*20.0f);
}

// 更新処理
void EnemyStateCaughtStandard::update(float deltaTime) {
}

// 終了時の処理
void EnemyStateCaughtStandard::end() {
}

// メッセージ処理
void EnemyStateCaughtStandard::handleMessage(EventMessage message, void* param) {
	switch (message)
	{
	case EventMessage::PLAYER_CRUSH:
		change(EnemyStateName::Crush);
		p_Enemy.lock()->GetHitPoint().Decrease(1 + (int)param);
		break;

	case EventMessage::PLAYER_RELEASE:
		change(EnemyStateName::Stop);
		break;
	}
}