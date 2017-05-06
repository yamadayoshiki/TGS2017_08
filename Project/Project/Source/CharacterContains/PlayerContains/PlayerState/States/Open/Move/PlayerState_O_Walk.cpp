#include"PlayerState_O_Walk.h"

//コンストラクタ
PlayerState_O_Walk::PlayerState_O_Walk(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_O_MoveBase(position,matrix,player,gameManager)
{

}
//各状態独自の初期化
void PlayerState_O_Walk::onUniqueInit()
{

}
//更新処理
void PlayerState_O_Walk::onUpdate(float deltaTime)
{
	move(deltaTime, 1.0f);
}