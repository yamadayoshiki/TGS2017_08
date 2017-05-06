#include"PlayterState_R_Run.h"

//コンストラクタ
PlayerState_R_Run::PlayerState_R_Run(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_R_MoveBase(position, matrix,player, gameManager)
{

}
//各状態独自の初期化
void PlayerState_R_Run::onUniqueInit()
{

}
//更新処理
void PlayerState_R_Run::onUpdate(float deltaTime)
{
	move(deltaTime, 3.5);
}