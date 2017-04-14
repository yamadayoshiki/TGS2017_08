#pragma once

#include "../../PlayerState.h"

// 通常時のジャンプ状態
class PlayerState_N_Jump : public PlayerState {
public:
	// コンストラクタ
	PlayerState_N_Jump(Vector3& pos, Matrix& mat);
	// 各状態独自の初期化
	virtual void unique_init(Actor & actor) override;
	// 更新処理
	virtual void update(Actor & actor, float deltaTime) override;
	// 衝突判定
	virtual void collide(const Actor & other) override;
	// 終了時の処理
	virtual void end() override;
	// 入力処理
	virtual void input() override;
private:
	float mJumpPower;
};