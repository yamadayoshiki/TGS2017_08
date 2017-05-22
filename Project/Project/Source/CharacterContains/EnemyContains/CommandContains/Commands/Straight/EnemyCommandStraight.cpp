#include "EnemyCommandStraight.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Map/Map.h"
#include "../../../../../Define/Def_GSvector2.h"
#include"../../../../../Define/Def_Nakayama.h"	//for CHIP_SIZE
#include "../../../../../Define/Def_Float.h"	//for FLOAT_EPSILON
#include "../../../../../Map/MapType.h"

//コンストラクタ
EnemyCommandStraight::EnemyCommandStraight(const EnemyBasePtr& enemy, const FourDirection front, const MapType type)
	: EnemyCommandBase(enemy)
	, m_NextTargetPos(GSVECTOR2_ZERO)
	, m_CurFront(front)
	, m_Type(type) {
	//SetNextTargetPos();
}

void EnemyCommandStraight::Initialize()
{
	SetNextTargetPos();

}

//更新
void EnemyCommandStraight::Update(float deltaTime) {
	//目標地点までの距離
	m_Velocity = m_NextTargetPos - p_Enemy->getPosition();
	//目標地点にたどり着いているか
	if (m_Velocity.length() <= FLOAT_EPSILON)
	{
		HitWallReaction();
		SetNextTargetPos();
	}
}

//終了
void EnemyCommandStraight::Finalize() {

}

//各種固有の初期化
void EnemyCommandStraight::OnInitialize() {

}

//正面に壁があった場合のリアクション
void EnemyCommandStraight::HitWallReaction() {
	TurnBack();
}

//折り返す
void EnemyCommandStraight::TurnBack() {
	//正面を反転
	m_CurFront.TurnOver();
}

//正面に壁があるか
bool EnemyCommandStraight::CheckFrontWall() {
	//正面の向きをFourDirection	に置き換え
	FourDirection front = FourDirection(p_Enemy->getTransform().m_Angle);
	//自分の周辺のタイルデータ配列
	std::unordered_map<FourDirection, TileData> mapDate
		= p_Enemy->getWorld()->GetMap().GetAroundTile(p_Enemy->getPosition());
	//正面に壁があるか
	if (mapDate[front].Flag() == 1)
		return true;
	else
		return false;
}

//次の目標地点を設定する
void EnemyCommandStraight::SetNextTargetPos() {
	//正面のマップ配列
	std::vector<int> line = GetFrontMapData(m_CurFront.name, m_Type);

	//進行可能マス数
	int chipNum = 0;

	//正面何マス目まで進めるか
	for (int i = 0; i < line.size(); i++)
	{
		//壁マスか
		if (line[i] == 1)
			break;

		else
			chipNum++;
	}

	//進行ベクトル
	GSvector2 frontVector = m_CurFront.GetVector2();
	frontVector = frontVector * (CHIP_SIZE* ((int)m_Type + 1)) * chipNum;
	//次の目標地点の設定
	m_NextTargetPos = p_Enemy->getPosition() + frontVector;
}