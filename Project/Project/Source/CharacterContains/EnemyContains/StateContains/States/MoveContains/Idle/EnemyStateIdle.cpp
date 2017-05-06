#include "EnemyStateIdle.h"

//コンストラクタ
EnemyStateIdle::EnemyStateIdle(const EnemyBasePtr& enemy)
	:EnemyStateMoveBase(enemy)
{
}

//各状態固有の初期化
void EnemyStateIdle::onUniqueInit()
{
	//アニメーションの変更

}