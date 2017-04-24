#include"PlayerState_O_Run.h"

//コンストラクタ
PlayerState_O_Run::PlayerState_O_Run(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState_O_MoveBase(position,matrix,gameManager)
{

}
//各状態独自の初期化
void PlayerState_O_Run::onUniqueInit(Actor& actor)
{

}
//更新処理
void PlayerState_O_Run::onUpdate(Actor& actor, float deltaTime)
{
	move(actor, deltaTime, 1.5);
}