#include "PlayerState_Crush_Barrage.h"


//コンストラクタ
PlayerState_Crush_Barrage::PlayerState_Crush_Barrage(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_CrushBase(player, gameManager)
{

}

//各状態独自の初期化
void PlayerState_Crush_Barrage::onUniqueInit()
{
}

//更新処理
void PlayerState_Crush_Barrage::onUpdate(float deltaTime)
{
	change(PlayerStateName::Rounds);
}
