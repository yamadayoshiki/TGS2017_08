#include"PlayerState_Crush_Hold.h"

//コンストラクタ
PlayerState_Crush_Hold::PlayerState_Crush_Hold(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState_CrushBase(position,matrix,gameManager)
{

}
//各状態独自の初期化
void PlayerState_Crush_Hold::onUniqueInit(Actor& actor)
{

}
//更新処理
void PlayerState_Crush_Hold::onUpdate(Actor& actor, float deltaTime)
{

}