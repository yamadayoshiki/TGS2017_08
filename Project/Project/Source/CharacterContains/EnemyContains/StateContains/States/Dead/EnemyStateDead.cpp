#include "EnemyStateDead.h"

//コンストラクタ
EnemyStateDead::EnemyStateDead(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {

}
// 各状態独自の初期化
void EnemyStateDead::unique_init() {
	//アニメーションの変更

}
// 更新処理
void EnemyStateDead::update(float deltaTime) {
	//アニメーションが終了したらActorから削除

}
// 衝突判定
void EnemyStateDead::collide(const Actor & other) {

}
// 終了時の処理
void EnemyStateDead::end() {

}