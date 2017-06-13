#include "EnemyCommandStraight.h"
#include "../../../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../../WorldContains/IWorld.h"
#include "../../../../../../../Define/Def_GSvector2.h"
#include "../../../../../../../Define/Def_Nakayama.h"	//for CHIP_SIZE
#include "../../../../../../../Define/Def_Float.h"		//for FLOAT_EPSILON
#include "../../../../../../../FrontChipList/FrontChipList.h"
#include "../../../../../../../Map/Map.h"

//コンストラクタ
EnemyCommandStraight::EnemyCommandStraight(
	const EnemyBasePtr& enemy,
	const MapType type)
	: EnemyCommandMoveBase(
		enemy,
		type){
}

//目標地点に到着したリアクション
void EnemyCommandStraight::ArriveReaction() {
	//正面に壁があった場合のリアクション
	HitWallReaction();
}

//次の目標地点を設定する
void EnemyCommandStraight::SetNextTargetPos() {
	//正面のマップ配列
	FrontChipList list = FrontChipList(p_Enemy.lock()->getWorld()->GetMap(), p_Enemy.lock()->getPosition(), p_Enemy.lock()->GetDirection(), m_Type);
	//進行ベクトル
	GSvector2 frontVector = p_Enemy.lock()->GetDirection().GetVector2();
	frontVector = frontVector * (CHIP_SIZE* ((int)m_Type + 1)) * list.GetSpeaceNum();
	//次の目標地点の設定
	m_NextTargetPos = p_Enemy.lock()->getWorld()->GetMap()->GetTilePos(p_Enemy.lock()->getPosition(), m_Type) + frontVector;
}

//正面に壁があった場合のリアクション
void EnemyCommandStraight::HitWallReaction() {
	//向きを反転
	p_Enemy.lock()->SetDirection(p_Enemy.lock()->GetDirection().GetTurnOver());
	//次の目標地点を設定
	SetNextTargetPos();
}