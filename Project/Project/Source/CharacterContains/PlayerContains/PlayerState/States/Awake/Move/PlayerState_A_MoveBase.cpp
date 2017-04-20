#include"PlayerState_A_MoveBase.h"
#include"../../../PlayerStateName.h"

//コンストラクタ
PlayerState_A_MoveBase::PlayerState_A_MoveBase(GSvector2& pos)
	:PlayerState(pos){}

//各状態独自の初期化
void PlayerState_A_MoveBase::unique_init(Actor& actor)
{
	// 継承先の各状態独自の初期化
	onUniqueInit(actor);
}
//更新処理
void PlayerState_A_MoveBase::update(Actor& actor, float deltaTaime)
{
	//移動の入力状態によって状態を変更(待機、歩く)
	if (mInput->PadVelocity().length() <= 0.0f) {
		change(PlayerStateName::Idol);
	}
	else if (mInput->PadVelocity().length() <= 1.0f) {
		change(PlayerStateName::Walk);
	}

	//継承先の更新処理
	onUpdate(actor, deltaTaime);
}
//衝突判定
void PlayerState_A_MoveBase::collide(const Actor& other)
{
	//継承先の衝突処理
	onCollide(other);
}
//終了処理
void PlayerState_A_MoveBase::end()
{
	//継承先の終了処理
	onEnd();
}
//入力処理
void PlayerState_A_MoveBase::input()
{
	//ダッシュ
	if (mInput->IsPadState(GS_XBOX_PAD_A) && (mInput->PadVelocity().length() >= 1.0f)) change(PlayerStateName::Run);
	//


	//継承先の入力処理
	onInput();
}