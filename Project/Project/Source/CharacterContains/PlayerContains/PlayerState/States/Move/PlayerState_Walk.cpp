#include"PlayerState_Walk.h"

//コンストラクタ
PlayerState_Walk::PlayerState_Walk(GSvector2& pos)
	:PlayerState_MoveBase(pos){

}
//各状態独自の初期化
void PlayerState_Walk::onUniqueInit(Actor& actor) {

}
//更新処理
void PlayerState_Walk::onUpdate(Actor& actor, float deltaTime)
{
	//移動処理
	move(actor, deltaTime, 1.0f);
}