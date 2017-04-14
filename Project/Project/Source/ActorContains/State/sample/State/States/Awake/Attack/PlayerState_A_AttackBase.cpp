#include "PlayerState_A_AttackBase.h"

#include "../../../PlayerState_Enum.h"
#include "../../../../Player_AttackRange.h"
#include "../../../../../../Base/ActorGroup.h"
#include "../../../../../../../Scene/Base/SceneData.h"
#include "../../../../../../../World/World.h"
#include "../../../../../../../Define.h"

// コンストラクタ
PlayerState_A_AttackBase::PlayerState_A_AttackBase(Vector3 & pos, Matrix & mat) : PlayerState(pos, mat), mStartPos(Vector3::Zero) {}

// 各状態独自の初期化
void PlayerState_A_AttackBase::unique_init(Actor & actor){
	// 攻撃判定の生成
	actor.getWorld()->addActor(ActorGroup::PLAYER_ATTACK_RANGE, std::make_shared<Player_AttackRange>(actor.getWorld(), mPosition + Vector3::Up * 20 + actor.getPose().Backward() * 15 * 2));
	// 座標の代入
	mStartPos = mPosition;
	
	// 継承先の各状態独自の初期化
	onUniqueInit(actor);
}

// 更新処理
void PlayerState_A_AttackBase::update(Actor & actor, float deltaTime){
	// 重力の加算
	mPosition += Vector3::Down * GRAVITY;
	// 攻撃時に前方に移動
	mPosition = Vector3::Lerp(mPosition, mStartPos + actor.getPose().Backward() * 15, 0.4f);

	// アニメーションが終了した場合IDLEに遷移
	if (actor.getAnim().isAnimEnd()) {
		change(PlayerState_Enum::A_IDLE);
	}

	// 体力の減少
	actor.getWorld()->getSceneData()->getCurData().status.addDamage(PLAYER_AWAKE_BLOOD_USE);
	if (actor.getWorld()->getSceneData()->getCurData().status.mParams.hp <= 20) {
		change(PlayerState_Enum::NORMAL);
	}
	// 継承先の更新処理
	onUpdate(actor, deltaTime);
}

// 衝突判定
void PlayerState_A_AttackBase::collide(const Actor & other){
	// 継承先の衝突判定
	onCollide(other);
}

// 終了時の処理
void PlayerState_A_AttackBase::end(){
	// 継承先の終了時の処理
	onEnd();
}

// 入力処理
void PlayerState_A_AttackBase::input(){
	// 継承先の入力処理
	onInput();
}

