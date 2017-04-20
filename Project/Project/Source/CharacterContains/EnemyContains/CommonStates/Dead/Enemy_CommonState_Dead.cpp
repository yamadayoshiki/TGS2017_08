#include "Enemy_CommonState_Dead.h"

//コンストラクタ
Enemy_CommonState_Dead::Enemy_CommonState_Dead(
	GSvector2& pos, 
	GSmatrix4& mat) 
:Enemy_BaseState(pos,mat){

}
// 各状態独自の初期化
void Enemy_CommonState_Dead::unique_init(Actor & actor) {
}
// 更新処理
void Enemy_CommonState_Dead::update(Actor & actor, float deltaTime) {
}
// 衝突判定
void Enemy_CommonState_Dead::collide(const Actor & other) {

}
// 終了時の処理
void Enemy_CommonState_Dead::end() {

}