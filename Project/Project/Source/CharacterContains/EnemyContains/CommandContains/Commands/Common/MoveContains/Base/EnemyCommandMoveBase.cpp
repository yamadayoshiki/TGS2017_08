#include "EnemyCommandMoveBase.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../../Define/Def_Float.h"
#include "../../../../../../../Define/Def_GSvector2.h"
#include "../../../../../../../Map/Map.h"

//コンストラクタ
EnemyCommandMoveBase::EnemyCommandMoveBase(
	const EnemyBasePtr & enemy,
	const MapType type)
	: EnemyCommandBase(enemy)
	, m_Type(type)
	, m_NextTargetPos(GSVECTOR2_ZERO){
}

//各種固有の初期化
void EnemyCommandMoveBase::OnInitialize(){
	//目的地設定
	SetNextTargetPos();
}

//各種固有の更新
void EnemyCommandMoveBase::OnUpdate(float deltaTime){
	//目標地点までの距離
	m_Velocity = m_NextTargetPos - p_Enemy.lock()->getPosition();
	//目標地点にたどり着いているか
	if (m_Velocity.length() <= FLOAT_EPSILON)
		//目標地点に到着したリアクション
		ArriveReaction();
}