#include "EnemyStateMove.h"
#include "../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"
#include "../../../../Enemys/Base/EnemyBase.h"

//コンストラクタ
EnemyStateMove::EnemyStateMove(const EnemyBasePtr& enemy, const float speed)
	: EnemyStateMoveBase(enemy)
	, m_Speed(speed) {
}

//各状態固有の初期化
void EnemyStateMove::onUniqueInit() {
	//アニメーションの変更

}

// 更新処理
void EnemyStateMove::onUpdate(float deltaTime) {
	if (p_Enemy.lock()->GetCommandManager()->IsRegard() == false)
		ForwardMove(deltaTime, m_Speed);

	else
		RegardMove(p_Enemy.lock()->GetDirection(), deltaTime, m_Speed);
}