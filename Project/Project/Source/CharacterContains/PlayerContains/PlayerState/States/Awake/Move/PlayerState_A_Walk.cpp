#include"PlayerState_A_Walk.h"

//コンストラクタ
PlayerState_A_Walk::PlayerState_A_Walk(GSvector2& position, GSmatrix4& matrix, IGameManager* gameManager)
	:PlayerState_A_MoveBase(position,matrix,gameManager)
{

}
//各状態独自の初期化
void PlayerState_A_Walk::onUniqueInit(Actor& actor)
{

}
//更新処理
void PlayerState_A_Walk::onUpdate(Actor& actor, float deltaTime)
{
	move(actor, deltaTime, 1.0f);
}