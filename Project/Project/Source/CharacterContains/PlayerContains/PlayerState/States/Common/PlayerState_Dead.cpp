#include"PlayerState_Dead.h"

//コンストラクタ
PlayerState_Dead::PlayerState_Dead(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(position,matrix,player,gameManager)
{

}
//各状態独自の初期化
void PlayerState_Dead::unique_init()
{
	
}
//更新処理
void PlayerState_Dead::update(float deltaTaime)
{

}

//終了処理
void PlayerState_Dead::end()
{
	
}