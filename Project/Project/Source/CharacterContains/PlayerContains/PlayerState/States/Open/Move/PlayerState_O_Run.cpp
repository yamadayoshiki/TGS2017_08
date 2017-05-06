#include"PlayerState_O_Run.h"

//コンストラクタ
PlayerState_O_Run::PlayerState_O_Run(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_O_MoveBase(position, matrix, player, gameManager)
{

}
//各状態独自の初期化
void PlayerState_O_Run::onUniqueInit()
{

}
//更新処理
void PlayerState_O_Run::onUpdate(float deltaTime)
{
	move(deltaTime, 3.5);
}