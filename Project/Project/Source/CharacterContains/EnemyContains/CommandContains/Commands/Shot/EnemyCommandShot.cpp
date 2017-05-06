#include "EnemyCommandShot.h"
#include "../../../Enemys/Base/EnemyBase.h"

//コンストラクタ
EnemyCommandShot::EnemyCommandShot(const EnemyBasePtr& enemy)
	:EnemyCommandBase(enemy) {
}

//各種固有の初期化
void EnemyCommandShot::OnInitialize() {

}

//更新
void EnemyCommandShot::Update(float deltaTime) {
}

//終了
void EnemyCommandShot::Finalize() {

}

//終了チェック
bool EnemyCommandShot::IsEnd() {
	return true;
}
//命令ステート
EnemyStateName EnemyCommandShot::GetCurrentStateName() const {
	return EnemyStateName::Shot;
}