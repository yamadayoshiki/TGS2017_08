#include"PlayerState_O_Idol.h"

//コンストラクタ
PlayerState_O_Idol::PlayerState_O_Idol(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState_O_MoveBase(position,matrix,gameManager)
{

}

//各状態独自の初期化
void PlayerState_O_Idol::onUniqueInit(Actor& actor)
{

}