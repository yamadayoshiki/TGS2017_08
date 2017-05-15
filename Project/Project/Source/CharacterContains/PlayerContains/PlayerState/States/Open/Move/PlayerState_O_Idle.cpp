#include"PlayerState_O_Idle.h"

//コンストラクタ
PlayerState_O_Idle::PlayerState_O_Idle(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_O_MoveBase(player,gameManager)
{

}

//各状態独自の初期化
void PlayerState_O_Idle::onUniqueInit()
{

}