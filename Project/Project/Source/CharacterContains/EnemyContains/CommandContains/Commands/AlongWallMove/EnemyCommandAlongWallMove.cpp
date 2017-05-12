#include "EnemyCommandAlongWallMove.h"
#include "../../../../../Define/Def_GSvector2.h"

//コンストラクタ
EnemyCommandAlongWallMove::EnemyCommandAlongWallMove(const EnemyBasePtr& enemy, const TurnDirection turnDirection)
	:EnemyCommandBase(enemy)
	, m_TurnDirection(turnDirection)
	, m_NextTargetPos(GSVECTOR2_ZERO) {

}

//更新
void EnemyCommandAlongWallMove::Update(float deltaTime) {
}

//終了
void EnemyCommandAlongWallMove::Finalize() {

}

//回転方向の設定
void EnemyCommandAlongWallMove::SetturnDirection(TurnDirection turnDirection) {
	m_TurnDirection = turnDirection;
}

//各種固有の初期化
void EnemyCommandAlongWallMove::OnInitialize() {

}

//目標地点の設定
void EnemyCommandAlongWallMove::SetTargetPos() {
	switch (m_TurnDirection)
	{
	case TurnDirection::Clockwise:
		break;
	case TurnDirection::AntiClockwise:
		break;
	}
}