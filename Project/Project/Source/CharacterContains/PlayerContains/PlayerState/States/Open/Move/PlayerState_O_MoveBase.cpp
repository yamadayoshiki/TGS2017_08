#include"PlayerState_O_MoveBase.h"
#include"../../../PlayerStateName.h"

//コンストラクタ
PlayerState_O_MoveBase::PlayerState_O_MoveBase(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player,gameManager){}

//各状態独自の初期化
void PlayerState_O_MoveBase::unique_init()
{
	// 継承先の各状態独自の初期化
	onUniqueInit();
}
//更新処理
void PlayerState_O_MoveBase::update(float deltaTaime)
{
	if (p_Input->PadVelocity().length() >= 0.5f) {
		change(PlayerStateName::O_Walk);
	}
	else if (p_Input->PadVelocity().length() <= 0.0f) {
		change(PlayerStateName::O_Idle);
	}

	//継承先の更新処理
	onUpdate(deltaTaime);
}
//衝突判定
void PlayerState_O_MoveBase::collide(const Actor& other)
{
	//アームに当たっていたら返す
	if (m_Children[ActorName::Player_Arm]->isCollide(other)) return;

	if (other.getName() == ActorName::Enemy_01)
	{
		change(PlayerStateName::Damage);
	}
	//継承先の衝突処理
	onCollide(other);
}
//終了処理
void PlayerState_O_MoveBase::end()
{
	//継承先の終了処理
	onEnd();
}
//入力処理
void PlayerState_O_MoveBase::input()
{
	if (p_Input->IsPadStatesDetach(GS_XBOX_PAD_B)) {
		change(PlayerStateName::Swich);
	}
	//継承先の入力処理
	onInput();
}