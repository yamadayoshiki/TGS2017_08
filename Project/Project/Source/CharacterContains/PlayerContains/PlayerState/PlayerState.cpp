#include"PlayerState.h"

//コンストラクタ
PlayerState::PlayerState(GSvector2& pos)
	:mPosition(pos),mVelocity(GSvector2(0.0f,0.0f)),mAngle(0)
{}
//パッド入力
void PlayerState::input() {}

//モーション変更
void PlayerState::motion_change(Actor& actor, const PlayerStateID)
{

}
//移動処理
void PlayerState::move(Actor& actor, float deltaTime, float speed = 1.0f)
{
	mPosition += mVelocity * speed;
}
//覚醒条件(パッド)
bool PlayerState::aweke_pad()
{

}