#include "EnemyStateIdleStandard.h"

//コンストラクタ
EnemyStateIdleStandard::EnemyStateIdleStandard(const EnemyBasePtr& enemy)
	: EnemyStateBase(enemy)
	, EnemyStateMoveBaseStandard(enemy){
}

//各状態固有の初期化
void EnemyStateIdleStandard::onUniqueInit()
{
	//アニメーションの変更

}