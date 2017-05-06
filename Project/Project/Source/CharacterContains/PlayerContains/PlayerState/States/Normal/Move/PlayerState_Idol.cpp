#include"PlayerState_Idol.h"

//コンストラクタ
PlayerState_Idol::PlayerState_Idol(GSvector2& position,GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_MoveBase(position,matrix,player,gameManager){
}

//各状態独自の初期化
void PlayerState_Idol::onUniqueInit()
{

}