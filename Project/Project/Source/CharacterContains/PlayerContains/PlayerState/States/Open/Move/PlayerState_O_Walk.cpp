#include"PlayerState_O_Walk.h"

//コンストラクタ
PlayerState_O_Walk::PlayerState_O_Walk(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState_O_MoveBase(player,gameManager)
{

}
//各状態独自の初期化
void PlayerState_O_Walk::onUniqueInit()
{

}
//更新処理
void PlayerState_O_Walk::onUpdate(float deltaTime)
{
	//移動処理
	PlayerState::move(deltaTime, 8.0f);
	//アームの更新
	PlayerState::armUpdate();
}