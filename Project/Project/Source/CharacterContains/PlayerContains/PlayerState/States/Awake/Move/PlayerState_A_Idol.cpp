#include"PlayerState_A_Idol.h"

//コンストラクタ
PlayerState_A_Idol::PlayerState_A_Idol(GSvector2& position, GSmatrix4& matrix, IGameManager* gameManager)
	:PlayerState_A_MoveBase(position,matrix,gameManager)
{

}

//各状態独自の初期化
void PlayerState_A_Idol::onUniqueInit(Actor& actor)
{

}