#include"PlayerState_A_Run.h"

//コンストラクタ
PlayerState_A_Run::PlayerState_A_Run(GSvector2& position, GSmatrix4& matrix, IGameManager* gameManager)
	:PlayerState_A_MoveBase(position,matrix,gameManager)
{

}
//各状態独自の初期化
void PlayerState_A_Run::onUniqueInit(Actor& actor)
{

}
//更新処理
void PlayerState_A_Run::onUpdate(Actor& actor, float deltaTime)
{
	move(actor, deltaTime, 1.5);
}