#include "PlayerState_A_Quick.h"

// コンストラクタ
PlayerState_A_Quick::PlayerState_A_Quick(Vector3& pos, Matrix& mat) : PlayerState(pos, mat) {}

// 各状態固有の初期化
void PlayerState_A_Quick::unique_init(Actor & actor) {}

// 更新処理
void PlayerState_A_Quick::update(Actor & actor, float  deltaTime) {}

// 衝突判定
void PlayerState_A_Quick::collide(const Actor & other){}

// 終了時の処理
void PlayerState_A_Quick::end() { }

// 入力処理
void PlayerState_A_Quick::input() {}

