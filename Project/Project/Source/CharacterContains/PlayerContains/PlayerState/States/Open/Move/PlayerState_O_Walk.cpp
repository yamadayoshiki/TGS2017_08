#include"PlayerState_O_Walk.h"

//コンストラクタ
PlayerState_O_Walk::PlayerState_O_Walk(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState_O_MoveBase(position,matrix,gameManager)
{

}
//各状態独自の初期化
void PlayerState_O_Walk::onUniqueInit(Actor& actor)
{

}
//更新処理
void PlayerState_O_Walk::onUpdate(Actor& actor, float deltaTime)
{
	move(actor, deltaTime, 1.0f);
}