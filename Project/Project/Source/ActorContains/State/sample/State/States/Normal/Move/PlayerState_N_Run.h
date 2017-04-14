#pragma once

#include "PlayerState_N_MoveBase.h"

// 通常時の走り状態
class PlayerState_N_Run : public PlayerState_N_MoveBase {
public:
	// コンストラクタ
	PlayerState_N_Run(Vector3& pos, Matrix& mat);
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
};