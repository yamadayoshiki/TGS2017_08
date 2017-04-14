#pragma once

#include "../../../State/Base/State.h"

enum class PlayerMotionID;

// 各プレイヤーステートの基底クラス
class PlayerState : public State {
public:
	// コンストラクタ
	PlayerState(Vector3& pos, Matrix& mat);
	// パッド入力処理
	virtual void input() override;
protected:
	// モーションの切り替え
	void change_motion(Actor& actor, const PlayerMotionID id, const float speed = 1.0f);
	// 移動処理
	void move(Actor & actor, float deltaTime, float speed = 1.0f);
	// 覚醒条件(パッド)
	bool awake_pad();
protected:
	// 座標の参照
	Vector3& mPosition;
	// 行列の参照
	Matrix&  mRotation;
	// 速度
	Vector3 mVelocity;
	// 回転角度
	float mAngle;
};