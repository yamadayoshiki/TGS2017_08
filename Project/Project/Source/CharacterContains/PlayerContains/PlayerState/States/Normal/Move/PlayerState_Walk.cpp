#include"PlayerState_Walk.h"

//コンストラクタ
PlayerState_Walk::PlayerState_Walk(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_MoveBase(position, matrix, player, gameManager) {

}
//各状態独自の初期化
void PlayerState_Walk::onUniqueInit() {

}
//更新処理
void PlayerState_Walk::onUpdate(float deltaTime)
{
	//if (p_Input->IsPadState(GS_XBOX_PAD_A)) {
	//	change(PlayerStateName::Run);
	//}
	//移動処理
	move(deltaTime, 1.0f);
}