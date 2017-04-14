#pragma once

#include "../../PlayerState.h"

// 覚醒状態から通常時への遷移中の状態
class PlayerState_Normal : public PlayerState {
public:
	// コンストラクタ
	PlayerState_Normal(Vector3& pos, Matrix& mat);
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
};
