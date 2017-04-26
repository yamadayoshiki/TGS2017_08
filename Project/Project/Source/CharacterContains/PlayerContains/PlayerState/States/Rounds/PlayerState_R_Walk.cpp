#include"PlayerState_R_Walk.h"

//コンストラクタ
PlayerState_R_Walk::PlayerState_R_Walk(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState_R_MoveBase(position, matrix, gameManager)
{

}
//各状態独自の初期化
void PlayerState_R_Walk::onUniqueInit(Actor& actor)
{

}
//更新処理
void PlayerState_R_Walk::onUpdate(Actor& actor, float deltaTime)
{
	move(actor, deltaTime, 1.0f);
}