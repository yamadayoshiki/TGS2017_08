#include"PlayerState_Walk.h"

//コンストラクタ
PlayerState_Walk::PlayerState_Walk(GSvector2& position,GSmatrix4& matrix, GameManager* gameManager)
	:PlayerState_MoveBase(position,matrix,gameManager){

}
//各状態独自の初期化
void PlayerState_Walk::onUniqueInit(Actor& actor) {

}
//更新処理
void PlayerState_Walk::onUpdate(Actor& actor, float deltaTime)
{
	//if (p_Input->IsPadState(GS_XBOX_PAD_A)) {
	//	change(PlayerStateName::Run);
	//}
	//移動処理
	move(actor, deltaTime, 1.0f);
}