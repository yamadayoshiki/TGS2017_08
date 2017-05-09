#include"PlayerState_MoveBase.h"


//コンストラクタ
PlayerState_MoveBase::PlayerState_MoveBase(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(position, matrix, player, gameManager) {}

//各状態独自の初期化
void PlayerState_MoveBase::unique_init()
{
	// 継承先の各状態独自の初期化
	onUniqueInit();
}
//更新処理
void PlayerState_MoveBase::update(float deltaTaime)
{
	//移動の入力状態によって状態を変更(待機、歩く)
	if (p_Input->IsPadState(GS_XBOX_PAD_A)) {
		change(PlayerStateName::Run);
	}
	else if (p_Input->PadVelocity().length() >= 0.5f) {
		change(PlayerStateName::Walk);
	}
	else if (p_Input->PadVelocity().length() <= 0.0f) {
		change(PlayerStateName::Idle);
	}

	//継承先の更新処理
	onUpdate(deltaTaime);
}
//衝突判定
void PlayerState_MoveBase::collide(const Actor& other)
{
	if (other.getName() == ActorName::Enemy)
	{

	}
	//継承先の衝突処理
	onCollide(other);
}
//終了処理
void PlayerState_MoveBase::end()
{
	//継承先の終了処理
	onEnd();
}
//入力処理
void PlayerState_MoveBase::input()
{
	//アームを開く
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_B))
		change(PlayerStateName::Open);

	//if (p_Input->IsPadStatesDetach(GS_XBOX_PAD_B)) {
	//	change(PlayerStateName::Swich);
	//}

	//継承先の入力処理
	onInput();
}