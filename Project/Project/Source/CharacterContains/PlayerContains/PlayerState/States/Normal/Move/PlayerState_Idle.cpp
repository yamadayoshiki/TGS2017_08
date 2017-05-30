#include"PlayerState_Idle.h"

//コンストラクタ
PlayerState_Idle::PlayerState_Idle(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_MoveBase(player,gameManager){
}

//各状態独自の初期化
void PlayerState_Idle::onUniqueInit()
{
	TextureName_Change("Player_Close");
}