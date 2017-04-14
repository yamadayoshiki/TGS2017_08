#include "PlayerState_A_MoveBase.h"

#include "../../../PlayerState_Enum.h"
#include "../../../../PlayerMotionID.h"
#include "../../../../../../../Define.h"
#include "../../../../../../../Input/InputMgr.h"
#include "../../../../../../../World/World.h"
#include "../../../../../../../Scene/Base/SceneData.h"

// コンストラクタ
PlayerState_A_MoveBase::PlayerState_A_MoveBase(Vector3 & pos, Matrix & mat) : PlayerState(pos, mat) {}

// 各状態独自の初期化
void PlayerState_A_MoveBase::unique_init(Actor & actor){
	// 継承先の各状態独自の初期化
	onUniqueInit(actor);
}

// 更新処理
void PlayerState_A_MoveBase::update(Actor & actor, float deltaTime){
	// 重力を加算
	mPosition += Vector3::Down * GRAVITY;

	// 移動の入力状態によって状態を変更（待機、歩き、走り）
	if (InputMgr::GetInstance().AnalogPadVectorL().Length() <= 0) {
		change(PlayerState_Enum::A_IDLE);
	}
	else if (InputMgr::GetInstance().AnalogPadVectorL().Length() <= 0.5f) {
		change(PlayerState_Enum::A_WALK);
	}
	else {
		change(PlayerState_Enum::A_RUN);
	}

	// 徐々に体力を減らしていく
	actor.getWorld()->getSceneData()->getCurData().status.addDamage(PLAYER_AWAKE_BLOOD_USE);
	if (actor.getWorld()->getSceneData()->getCurData().status.mParams.hp <= 20) {
		change(PlayerState_Enum::NORMAL);
	}

	// 継承先の更新処理
	onUpdate(actor, deltaTime);
}

// 衝突判定
void PlayerState_A_MoveBase::collide(const Actor & other){
	//if (other.getName() == "Enemy_AttackRange") {
	//	change(PlayerState_Enum::DAMAGE);
	//}

	// 継承先の衝突判定
	onCollide(other);
}

// 終了時の処理
void PlayerState_A_MoveBase::end(){
	// 継承先の終了時の処理
	onEnd();
}

// 入力処理
void PlayerState_A_MoveBase::input(){
	// ジャンプ
	if (InputMgr::GetInstance().IsButtonDown(Buttons::BUTTON_CROSS))  change(PlayerState_Enum::A_JUMP);
	// ガード
	else if (InputMgr::GetInstance().IsButtonOn(Buttons::BUTTON_L1)) change(PlayerState_Enum::ROLL);
	// 攻撃1
	else if (InputMgr::GetInstance().IsButtonDown(Buttons::BUTTON_CIRCLE)) change(PlayerState_Enum::A_ATTACK1);
	// 覚醒状態に切り替え
	else if (awake_pad()) change(PlayerState_Enum::NORMAL);
	
	// 継承先の入力処理
	onInput();
}

