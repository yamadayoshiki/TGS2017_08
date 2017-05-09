#include"PlayerState_O_Idle.h"

//コンストラクタ
PlayerState_O_Idle::PlayerState_O_Idle(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_O_MoveBase(position,matrix,player,gameManager)
{

}

//各状態独自の初期化
void PlayerState_O_Idle::onUniqueInit()
{

}