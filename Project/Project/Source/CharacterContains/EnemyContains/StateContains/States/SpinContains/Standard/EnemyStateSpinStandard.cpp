#include "EnemyStateSpinStandard.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"
#include "../../../../PlayerWatch/PlayerWatch.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../../WorldContains/IWorld.h"

//コンストラクタ
EnemyStateSpinStandard::EnemyStateSpinStandard(const EnemyBasePtr & enemy, float speed)
	: EnemyStateBase(enemy)
	, m_Speed(speed) {
}

//各種固有の初期化
void EnemyStateSpinStandard::unique_init() {
	//アニメーション変更
	p_Enemy.lock()->Settexture("Attack");

	//プレイヤーに飛ばされる方向に向きを直す
	p_Enemy.lock()->SetDirection(p_Enemy.lock()->GetPlayerWatch()->GetPlayerFrontDir());

	//スピン状態に遷移したことを知らせる
	p_Enemy.lock()->GetCommandManager()->handleMessage(EventMessage::ENEMY_SPIN, nullptr);

	//プレイヤーに遷移したことを知らせる
	p_Enemy.lock()->getWorld()->findActor(ActorName::Player)->handleMessage(EventMessage::PLAYER_ROUNDSLOST,nullptr);
}

//各種固有の更新
void EnemyStateSpinStandard::update(float deltaTime) {
	ForwardMove(deltaTime, m_Speed);
}

void EnemyStateSpinStandard::end(){
	p_Enemy.lock()->Settexture("Normal");
}

//メッセージ処理
void EnemyStateSpinStandard::OnHandleMessage(EventMessage message, void * param){
	switch (message)
	{
	case EventMessage::ENEMY_COMMAND_DEAD:
		change(EnemyStateName::Dead);
	default:
		break;
	}
}
