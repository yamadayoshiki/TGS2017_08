#include "EnemyCommandEnemy01Straight.h"
#include "../../../../../../FrontChipList/FrontChipList.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../PlayerWatch/PlayerWatch.h"
#include "../../../../../../Define/Def_Float.h"
#include "../../../../../../Map/Map.h"

//コンストラクタ
EnemyCommandEnemy01Straight::EnemyCommandEnemy01Straight(
	const EnemyBasePtr & enemy)
	: EnemyCommandStraight(enemy, MapType::Double)
	, m_AxisChangeFlag(false) {
}

//各種固有の初期化
void EnemyCommandEnemy01Straight::OnInitialize() {
	//移動軸変更フラグ
	m_AxisChangeFlag = false;
	//プレイヤーとの距離ベクトル
	GSvector2 dis = p_Enemy.lock()->GetPlayerWatch()->GetToPlayerChipDis(MapType::Double);
	//プレイヤーがいる方向
	p_Enemy.lock()->SetDirection(FourDirection(dis));
	//目的地設定
	SetNextTargetPos();
}

//各種固有の更新
void EnemyCommandEnemy01Straight::OnUpdate(float deltaTime) {
	//プレイヤーと座標軸が一致しているか
	if (m_AxisChangeFlag == false)
		CheckAxisEnemyToPlayer();

	//親クラスの更新
	EnemyCommandStraight::OnUpdate(deltaTime);
}

//目標地点に到着したリアクション
void EnemyCommandEnemy01Straight::ArriveReaction() {
	//プレイヤーとの軸が一致した場合
	if (m_AxisChangeFlag == true)
	{
		Change(EnemyCommandName::Straight);
		return;
	}

	else
		HitWallReaction();
}

//正面に壁があった場合のリアクション
void EnemyCommandEnemy01Straight::HitWallReaction() {
	//正面のマップ配列
	FrontChipList list
		= FrontChipList(
			p_Enemy.lock()->getWorld()->GetMap(),
			p_Enemy.lock()->getPosition(),
			p_Enemy.lock()->GetDirection(),
			m_Type);

	//正面マップの空きマスがなかった場合逆方向を向く
	if (list.GetSpeaceExist() == false)
		EnemyCommandStraight::HitWallReaction();
	//迂回コマンドに変更
	else
		Change(EnemyCommandName::AlongWallMoveShoest);
}

//プレイヤーと座標軸が一致しているか
void EnemyCommandEnemy01Straight::CheckAxisEnemyToPlayer() {
	//マス準拠で同軸にいるか
	GSvector2 dis
		= p_Enemy.lock()->GetPlayerWatch()->GetToPlayerChipDis(MapType::Double);
	if (p_Enemy.lock()->GetDirection().GetVector2().x == 0)
		if (abs(dis.y) <= FLOAT_EPSILON)
			m_AxisChangeFlag = true;

	if (p_Enemy.lock()->GetDirection().GetVector2().y == 0)
		if (abs(dis.x) <= FLOAT_EPSILON)
			m_AxisChangeFlag = true;

	if (m_AxisChangeFlag == true)
		m_NextTargetPos
		= p_Enemy.lock()->getWorld()->
		GetMap().GetTilePos(p_Enemy.lock()->getPosition(), MapType::Double);
}