#include "EnemyStateMove.h"

//コンストラクタ
EnemyStateMove::EnemyStateMove(const EnemyBasePtr& enemy)
	:EnemyStateMoveBase(enemy)
{
}

//各状態固有の初期化
void EnemyStateMove::onUniqueInit()
{
	//アニメーションの変更

}

// 更新処理
void EnemyStateMove::onUpdate(float deltaTime) {
	//移動処理
	Move(deltaTime, 1.0f);
}