#include"PlayerState_Run.h"

//コンストラクタ
PlayerState_Run::PlayerState_Run(GSvector2& pos)
	:PlayerState_MoveBase(pos){

}
//各状態独自の初期化
void PlayerState_Run::onUniqueInit(Actor& actor)
{

}
//更新処理
void PlayerState_Run::onUpdate(Actor& actor, float deltaTime)
{
	//移動処理
	move(actor, deltaTime, 1.5f);
}