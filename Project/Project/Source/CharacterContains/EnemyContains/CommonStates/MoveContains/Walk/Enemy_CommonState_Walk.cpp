#include "Enemy_CommonState_Walk.h"

//コンストラクタ
Enemy_CommonState_Walk::Enemy_CommonState_Walk(GSvector2& pos, GSmatrix4& mat)
	:Enemy_CommonState_MoveBase(pos, mat)
{
}

// 各状態独自の初期化
void Enemy_CommonState_Walk::onUniqueInit(Actor & actor)
{

}

// 更新処理
void Enemy_CommonState_Walk::onUpdate(Actor& actor, float deltaTime)
{

}