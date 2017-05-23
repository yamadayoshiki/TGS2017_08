#include "EnemyStateCaught.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../PlayerContains/PlayerState/PlayerStateName.h"
#include "../../../../../WorldContains/EventMessage/EventMessage.h"

//コンストラクタ
EnemyStateCaught::EnemyStateCaught(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// 各状態独自の初期化
void EnemyStateCaught::unique_init() {
	// プレイヤーの取得
	ActorPtr player = p_Enemy->getWorld()->findActor(ActorName::Player);
	// プレイヤーの座標+前方
	p_Enemy->setPosition(player->getPosition() + player->getBody()->forward()*20.0f);
}

// 更新処理
void EnemyStateCaught::update(float deltaTime) {
}

// 衝突判定
void EnemyStateCaught::collide(const Actor & other) {

}

// 終了時の処理
void EnemyStateCaught::end() {
}

// メッセージ処理
void EnemyStateCaught::handleMessage(EventMessage message, void* param) {
	switch (message)
	{
	case EventMessage::PLAYER_CRUSH:
		change(EnemyStateName::Crush);
		break;

	case EventMessage::PLAYER_RELEASE:
		change(EnemyStateName::Stop);
		break;
	}
}