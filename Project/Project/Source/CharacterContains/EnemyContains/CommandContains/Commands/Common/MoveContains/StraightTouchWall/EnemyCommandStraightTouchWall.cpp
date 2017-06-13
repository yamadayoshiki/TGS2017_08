#include "EnemyCommandStraightTouchWall.h"
#include "../../../../../../../FrontChipList/FrontChipList.h"
#include "../../../../../../../Define/Def_Nakayama.h"	//for CHIP_SIZE
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../../WorldContains/IWorld.h"

//コンストラクタ
EnemyCommandStraightTouchWall::EnemyCommandStraightTouchWall(
	const EnemyBasePtr & enemy,
	const MapType type)
	: EnemyCommandStraight(enemy, type) {
}

//次の目標地点を設定する
void EnemyCommandStraightTouchWall::SetNextTargetPos(){
	//正面のマップ配列
	FrontChipList list = FrontChipList(p_Enemy.lock()->getWorld()->GetMap(), p_Enemy.lock()->getPosition(), p_Enemy.lock()->GetDirection(), m_Type);
	//次の目標地点の設定
	m_NextTargetPos = p_Enemy.lock()->getPosition() + (p_Enemy.lock()->GetDirection().GetVector2() * list.GetToWallLength(p_Enemy.lock()->getPosition(),p_Enemy.lock()->GetDirection(),16.0f));
}