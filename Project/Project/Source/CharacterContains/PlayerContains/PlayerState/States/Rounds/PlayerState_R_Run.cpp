#include"PlayterState_R_Run.h"

//コンストラクタ
PlayerState_R_Run::PlayerState_R_Run(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState_R_MoveBase(position, matrix, gameManager)
{

}
//各状態独自の初期化
void PlayerState_R_Run::onUniqueInit(Actor& actor)
{

}
//更新処理
void PlayerState_R_Run::onUpdate(Actor& actor, float deltaTime)
{
	move(actor, deltaTime, 3.5);
}