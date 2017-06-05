#include "EnemyCommandGenerate.h"

//コンストラクタ
EnemyCommandGenerate::EnemyCommandGenerate(
	const EnemyBasePtr & enemy,
	const MapType type,
	const TurnDirection turnDirection)
	:EnemyCommandBase(enemy) {
}

//デストラクタ
EnemyCommandGenerate::~EnemyCommandGenerate() {
}

//終了
void EnemyCommandGenerate::Finalize() {
}

//各種固有の初期化
void EnemyCommandGenerate::OnInitialize() {
}

//各種固有の更新
void EnemyCommandGenerate::OnUpdate(float deltaTime) {
}

