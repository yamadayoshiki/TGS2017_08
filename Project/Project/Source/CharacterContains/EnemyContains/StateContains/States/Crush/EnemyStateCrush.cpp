#include "EnemyStateCrush.h"

//コンストラクタ
EnemyStateCrush::EnemyStateCrush(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// 各状態独自の初期化
void EnemyStateCrush::unique_init() {
	//モーションの変更

}

// 更新処理
void EnemyStateCrush::update(float deltaTime) {
	//ダメージによるHPの減少


	//離されたら待機状態に遷移

}

// 衝突判定
void EnemyStateCrush::collide(const Actor & other) {
}

// 終了時の処理
void EnemyStateCrush::end() {
}

