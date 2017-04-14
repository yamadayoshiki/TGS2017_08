#pragma once

#include "../../../State/Base/StateMgr.h"

// 先行宣言
struct Vector3;
struct Matrix;

// プレイヤーステートのマネージャー
class PlayerStateMgr : public StateMgr{
public:
	// コンストラクタ
	PlayerStateMgr();
	// コンストラクタ
	PlayerStateMgr(Vector3& pos, Matrix& mat);
};