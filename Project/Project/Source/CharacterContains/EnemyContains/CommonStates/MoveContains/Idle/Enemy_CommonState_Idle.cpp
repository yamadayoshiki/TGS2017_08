#include "Enemy_CommonState_Idle.h"

//コンストラクタ
Enemy_CommonState_Idle::Enemy_CommonState_Idle(GSvector2& pos, GSmatrix4& mat)
	:Enemy_CommonState_MoveBase(pos, mat)
{
}

//各状態固有の初期化
void Enemy_CommonState_Idle::onUniqueInit(Actor& actor)
{
	//アニメーションの変更

}