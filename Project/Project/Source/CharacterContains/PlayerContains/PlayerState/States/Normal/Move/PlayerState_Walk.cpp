#include"PlayerState_Walk.h"

//コンストラクタ
PlayerState_Walk::PlayerState_Walk(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_MoveBase(player, gameManager) {

}
//各状態独自の初期化
void PlayerState_Walk::onUniqueInit() {

}
//更新処理
void PlayerState_Walk::onUpdate(float deltaTime)
{
	//移動処理
	move(deltaTime, 8.0f);
	//アームの更新
	armUpdate();
}