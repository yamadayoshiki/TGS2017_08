#include "PlayerState_Crush_Barrage.h"


//コンストラクタ
PlayerState_Crush_Barrage::PlayerState_Crush_Barrage(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState_CrushBase(position, matrix, gameManager)
{

}

//各状態独自の初期化
void PlayerState_Crush_Barrage::onUniqueInit(Actor & actor)
{
}

//更新処理
void PlayerState_Crush_Barrage::onUpdate(Actor & actor, float deltaTime)
{

}
