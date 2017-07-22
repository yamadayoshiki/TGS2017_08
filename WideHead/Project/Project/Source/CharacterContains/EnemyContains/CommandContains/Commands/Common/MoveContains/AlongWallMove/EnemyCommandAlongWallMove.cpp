#include "EnemyCommandAlongWallMove.h"
#include "../../../../../../../Define/Def_GSvector2.h"
#include "../../../../../../../WorldContains/IWorld.h"
#include "../../../../../../../Define/Def_Float.h"
#include "../../../../../../../TargetPosition/TargetPosition.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../../ActorContains/Transform/Transform.h"

//コンストラクタ
EnemyCommandAlongWallMove::EnemyCommandAlongWallMove(
	const EnemyBasePtr& enemy,
	const MapType type,
	const TurnDirection turnDirection)
	: EnemyCommandMoveBase(enemy, type)
	, m_TurnDirection(turnDirection)
	, p_TargetPosition(nullptr) {
	p_TargetPosition = new TargetPosition(p_Enemy.lock()->getWorld()->GetMap(), turnDirection, type);
}

//デストラクタ
EnemyCommandAlongWallMove::~EnemyCommandAlongWallMove() {
	delete p_TargetPosition;
}

//終了
void EnemyCommandAlongWallMove::Finalize() {
	p_TargetPosition->Clear();
}

//各種固有の初期化
void EnemyCommandAlongWallMove::OnInitialize() {
	Finalize();
	p_TargetPosition->AlongWall(p_Enemy.lock()->getPosition(), FourDirection(p_Enemy.lock()->getTransform()->m_Angle));
	m_NextTargetPos = p_TargetPosition->GetNextPos();
}

//各種固有の更新
void EnemyCommandAlongWallMove::OnUpdate(float deltaTime) {
	//目標地点までの距離
	m_Velocity = m_NextTargetPos - p_Enemy.lock()->getPosition();
	//目標地点にたどり着いているか
	if (m_Velocity.length() <= FLOAT_EPSILON) {
		ArriveReaction();
	}
}

//目標地点に到着したリアクション
void EnemyCommandAlongWallMove::ArriveReaction() {
	//目標地点の更新
	SetTargetPos();
}

//目標地点の設定
void EnemyCommandAlongWallMove::SetTargetPos() {
	p_TargetPosition->AlongWall();
	p_TargetPosition->Arrival();
	m_NextTargetPos = p_TargetPosition->GetNextPos();
	m_Velocity = m_NextTargetPos - p_Enemy.lock()->getPosition();
}