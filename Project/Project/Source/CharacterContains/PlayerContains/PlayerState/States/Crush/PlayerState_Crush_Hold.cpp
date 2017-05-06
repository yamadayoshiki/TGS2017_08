#include"PlayerState_Crush_Hold.h"

//コンストラクタ
PlayerState_Crush_Hold::PlayerState_Crush_Hold(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_CrushBase(position, matrix, player, gameManager)
{

}
//各状態独自の初期化
void PlayerState_Crush_Hold::onUniqueInit()
{

}
//更新処理
void PlayerState_Crush_Hold::onUpdate(float deltaTime)
{

}