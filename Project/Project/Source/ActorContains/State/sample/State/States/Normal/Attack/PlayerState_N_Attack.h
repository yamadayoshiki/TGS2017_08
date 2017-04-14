#pragma once

#include "PlayerState_N_AttackBase.h"

enum class  PlayerState_Enum;

// 通常時の攻撃状態
class PlayerState_N_Attack : public PlayerState_N_AttackBase {
public:
	// コンストラクタ
	PlayerState_N_Attack(Vector3& pos, Matrix& mat, PlayerMotionID motion, PlayerState_Enum next);
	// 各状態独自の初期化
	virtual void onUniqueInit(Actor & actor)override;
	// 更新処理
	virtual void onUpdate(Actor & actor, float deltaTime)override;
	// 衝突判定
	virtual void onCollide(const Actor & other)override {}
	// 終了時の処理
	virtual void onEnd()override {}
	// 入力処理
	virtual void onInput()override {}
private:
	// モーション
	PlayerMotionID mMotion;
	// コンボ時の遷移先
	PlayerState_Enum mNextState;
};
