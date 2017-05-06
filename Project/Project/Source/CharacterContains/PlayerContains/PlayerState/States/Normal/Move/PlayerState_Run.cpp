#include"PlayerState_Run.h"

//コンストラクタ
PlayerState_Run::PlayerState_Run(GSvector2& position,GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_MoveBase(position,matrix,player,gameManager){

}
//各状態独自の初期化
void PlayerState_Run::onUniqueInit()
{

}
//更新処理
void PlayerState_Run::onUpdate(float deltaTime)
{
	//移動処理
	move(deltaTime, 3.5f);
}