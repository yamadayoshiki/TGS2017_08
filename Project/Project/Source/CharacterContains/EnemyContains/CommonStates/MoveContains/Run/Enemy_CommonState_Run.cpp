#include "Enemy_CommonState_Run.h"

//コンストラクタ
Enemy_CommonState_Run::Enemy_CommonState_Run(
	GSvector2& pos,
	GSmatrix4& mat)
	:Enemy_CommonState_MoveBase(pos, mat) {
}
// 各状態独自の初期化
void Enemy_CommonState_Run::onUniqueInit(Actor & actor) {

}
// 更新処理
void Enemy_CommonState_Run::onUpdate(Actor & actor, float deltaTime) {
}