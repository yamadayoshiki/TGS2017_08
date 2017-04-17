#include"PlayerState_MoveBase.h"

//コンストラクタ
PlayerState_MoveBase::PlayerState_MoveBase(GSvector2& pos)
	:PlayerState(pos) {}

//各状態独自の初期化
void PlayerState_MoveBase::unique_init(Actor& actor)
{
	// 継承先の各状態独自の初期化
	onUniqueInit(actor);
}
//更新処理
void PlayerState_MoveBase::update(Actor& actor, float deltaTaime)
{

}
//衝突判定
void PlayerState_MoveBase::collide(const Actor& other)
{

}
//終了処理
void PlayerState_MoveBase::end()
{

}
//入力処理
void PlayerState_MoveBase::input()
{

}