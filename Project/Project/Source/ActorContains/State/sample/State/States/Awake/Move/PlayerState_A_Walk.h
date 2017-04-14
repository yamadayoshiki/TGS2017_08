#pragma once

#include "PlayerState_A_MoveBase.h"

// 覚醒時の歩き状態
class PlayerState_A_Walk : public PlayerState_A_MoveBase {
public:
	// コンストラクタ
	PlayerState_A_Walk(Vector3& pos, Matrix& mat);
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