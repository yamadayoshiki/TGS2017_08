#include "EnemyStateMoveStandard.h"
#include "../../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"

//コンストラクタ
EnemyStateMoveStandard::EnemyStateMoveStandard(const EnemyBasePtr& enemy, const float speed)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBaseStandard(enemy)
	, m_Speed(speed) {
}

//各状態固有の初期化
void EnemyStateMoveStandard::onUniqueInit() {
}

// 更新処理
void EnemyStateMoveStandard::onUpdate(float deltaTime) {
	//注視なし移動
	if (p_Enemy.lock()->GetCommandManager()->IsRegard() == false)
		ForwardMove(deltaTime, m_Speed);

	//注視あり移動
	else
		RegardMove(p_Enemy.lock()->GetDirection(), deltaTime, m_Speed);
}