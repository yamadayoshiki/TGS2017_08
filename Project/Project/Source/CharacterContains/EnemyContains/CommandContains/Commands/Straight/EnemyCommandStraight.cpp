#include "EnemyCommandStraight.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Define/Def_GSvector2.h"
#include"../../../../../Define/Def_Nakayama.h"	//for CHIP_SIZE
#include "../../../../../Define/Def_Float.h"	//for FLOAT_EPSILON
#include "../../../../../FrontChipList/FrontChipList.h"
#include "../../../../../Map/Map.h"

//コンストラクタ
EnemyCommandStraight::EnemyCommandStraight(
	const EnemyBasePtr& enemy,
	const MapType type)
	: EnemyCommandBase(enemy)
	, m_NextTargetPos(GSVECTOR2_ZERO)
	, m_Type(type) {
}

//終了
void EnemyCommandStraight::Finalize() {

}

//各種固有の初期化
void EnemyCommandStraight::OnInitialize() {
	//目的地設定
	SetNextTargetPos();
}

//各種固有の更新
void EnemyCommandStraight::OnUpdate(float deltaTime) {
	//目標地点までの距離
	m_Velocity = m_NextTargetPos - p_Enemy->getPosition();
	//目標地点にたどり着いているか
	if (m_Velocity.length() <= FLOAT_EPSILON)
		//目標地点に到着したリアクション
		ArriveReaction();
}

//目標地点に到着したリアクション
void EnemyCommandStraight::ArriveReaction() {
	//正面に壁があった場合のリアクション
	HitWallReaction();
}

//正面に壁があった場合のリアクション
void EnemyCommandStraight::HitWallReaction() {
	p_Enemy->SetDirection(p_Enemy->GetDirection().GetTurnOver());
	SetNextTargetPos();
}

//次の目標地点を設定する
void EnemyCommandStraight::SetNextTargetPos() {
	//正面のマップ配列
	FrontChipList list = FrontChipList(p_Enemy->getWorld()->GetMap(), p_Enemy->getPosition(), p_Enemy->GetDirection(), m_Type);
	//進行ベクトル
	GSvector2 frontVector = p_Enemy->GetDirection().GetVector2();
	frontVector = frontVector * (CHIP_SIZE* ((int)m_Type + 1)) * list.GetSpeaceNum();
	//次の目標地点の設定
	m_NextTargetPos = p_Enemy->getWorld()->GetMap().GetTilePos(p_Enemy->getPosition(), m_Type) + frontVector;
}