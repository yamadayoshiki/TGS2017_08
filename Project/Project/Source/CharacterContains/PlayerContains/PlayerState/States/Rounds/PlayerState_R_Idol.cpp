#include"PlayerState_R_Idol.h"

//コンストラクタ
PlayerState_R_Idol::PlayerState_R_Idol(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState_R_MoveBase(position, matrix, gameManager)
{

}

//各状態独自の初期化
void PlayerState_R_Idol::onUniqueInit(Actor& actor)
{

}