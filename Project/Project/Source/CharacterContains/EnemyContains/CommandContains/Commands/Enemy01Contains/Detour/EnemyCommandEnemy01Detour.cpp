#include "EnemyCommandEnemy01Detour.h"
#include "../../../../../../Define/Def_GSvector2.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../ActorContains/Transform/Transform.h"
#include "../../../../../../TargetPosition/TargetPosition.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../FrontChipList/FrontChipList.h"
#include "../../../../../../Define/Def_Nakayama.h"
#include "../../../../../../Utility/TurnDirection/TurnDirection.h"
#include "../../../../PlayerWatch/PlayerWatch.h"
#include "../../../../../../Define/Def_Float.h"
#include "../../../../../../ActorContains/Body/Base/IBody.h"
#include "../../../../../../Define/Def_GSvector2.h"
#include "../../../../../../Map/Map.h"

//コンストラクタ
EnemyCommandEnemy01Detour::EnemyCommandEnemy01Detour(
	const EnemyBasePtr & enemy)
	: EnemyCommandAlongWallMove(
		enemy,
		MapType::Double,
		TurnDirection(TurnDirectionName::None))
	, m_AxisChangeFlag(false) {
}

//デストラクタ
EnemyCommandEnemy01Detour::~EnemyCommandEnemy01Detour() {
}


//各種固有の初期化
void EnemyCommandEnemy01Detour::OnInitialize() {
	m_AxisChangeFlag = false;
	Finalize();
	p_TargetPosition->Clone(GetTargetPositionManager());
	m_NextTargetPos = p_TargetPosition->GetNextPos();
}

//各種固有の更新
void EnemyCommandEnemy01Detour::OnUpdate(float deltaTime) {
	//プレイヤーと座標軸が一致しているか
	if (m_AxisChangeFlag == false)
		CheckAxisEnemyToPlayer();

	//親クラスの更新
	EnemyCommandAlongWallMove::OnUpdate(deltaTime);
}

//目標地点に到着したリアクション
void EnemyCommandEnemy01Detour::ArriveReaction() {
	//プレイヤーとの軸が一致した場合
	if (m_AxisChangeFlag == true)
		Change(EnemyCommandName::Straight);

	else
		SetTargetPos();
}


//目標地点の設定
void EnemyCommandEnemy01Detour::SetTargetPos() {
	p_TargetPosition->Arrival();
	m_NextTargetPos = p_TargetPosition->GetNextPos();

	if (m_NextTargetPos == GSVECTOR2_ZERO)
		Change(EnemyCommandName::Straight);

	else
		m_Velocity = m_NextTargetPos - p_Enemy.lock()->getPosition();
}

//目標地点管理の設定
TargetPosition EnemyCommandEnemy01Detour::GetTargetPositionManager() {
	//時計回り
	TargetPosition targetPositionClockwise = TargetPosition(p_Enemy.lock()->getWorld()->GetMap(), TurnDirection(TurnDirectionName::Clockwise), MapType::Double);
	targetPositionClockwise.AlongWall(p_Enemy.lock()->getPosition(), p_Enemy.lock()->GetDirection().GetTurnOver());
	//反時計回り方向
	TargetPosition targetPositionAntiClockwise = TargetPosition(p_Enemy.lock()->getWorld()->GetMap(), TurnDirection(TurnDirectionName::AntiClockwise), MapType::Double);
	targetPositionAntiClockwise.AlongWall(p_Enemy.lock()->getPosition(), p_Enemy.lock()->GetDirection().GetTurnOver());
	//前方マス
	FrontChipList frontChipList = FrontChipList(p_Enemy.lock()->getWorld()->GetMap(), p_Enemy.lock()->getPosition(), p_Enemy.lock()->GetDirection(), MapType::Double);
	//ゴール地点までの距離
	float dis = frontChipList.GeTheOffSideOfTheWallChipNum() * ((int)MapType::Double + 1)*CHIP_SIZE;
	//ゴール地点
	GSvector2 goal = p_Enemy.lock()->getWorld()->GetMap()->GetTilePos(p_Enemy.lock()->getPosition(), MapType::Double) + p_Enemy.lock()->GetDirection().GetVector2() * dis;
	//ゴールにたどり着くまで
	while (true)
	{
		targetPositionClockwise.AlongWall();
		targetPositionAntiClockwise.AlongWall();

		if (targetPositionClockwise.GetLastPos() == goal)
			return targetPositionClockwise;

		else if (targetPositionAntiClockwise.GetLastPos() == goal)
			return targetPositionAntiClockwise;
	}
}

//プレイヤーと座標軸が一致しているか
void EnemyCommandEnemy01Detour::CheckAxisEnemyToPlayer() {
	//マス準拠で同軸にいるか
	GSvector2 dis = p_Enemy.lock()->GetPlayerWatch()->GetToPlayerChipDis(MapType::Double);
	if (p_Enemy.lock()->GetDirection().GetVector2().x == 0)
		if (abs(dis.y) <= FLOAT_EPSILON)
			m_AxisChangeFlag = true;

	if (p_Enemy.lock()->GetDirection().GetVector2().y == 0)
		if (abs(dis.x) <= FLOAT_EPSILON)
			m_AxisChangeFlag = true;

	if (m_AxisChangeFlag == true)
		m_NextTargetPos = p_Enemy.lock()->getWorld()->GetMap()->GetTilePos(p_Enemy.lock()->getPosition(),MapType::Double);
}