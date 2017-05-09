#include"PlayerState_R_Idle.h"

//コンストラクタ
PlayerState_R_Idle::PlayerState_R_Idle(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_R_MoveBase(position, matrix,player,gameManager)
{

}

//各状態独自の初期化
void PlayerState_R_Idle::onUniqueInit()
{

}