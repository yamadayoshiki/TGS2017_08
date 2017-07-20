#include "EnemyStateCrushStandard.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "..\..\Damage\EnemyStateDamage.h"


//コンストラクタ
EnemyStateCrushStandard::EnemyStateCrushStandard(const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// 各状態独自の初期化
void EnemyStateCrushStandard::unique_init() {
	//モーションの変更

}

// 更新処理
void EnemyStateCrushStandard::update(float deltaTime) {
	if (p_Enemy.lock()->GetHitPoint().IsDead() == true)
		change(EnemyStateName::Dead);

	else
		change(EnemyStateName::Caught);
}