#include "EnemyCommandStraight.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Map/Map.h"
#include "../../../../../Define/Def_GSvector2.h"
#include"../../../../../Define/Def_Nakayama.h"	//for CHIP_SIZE
#include "../../../../../Define/Def_Float.h"	//for FLOAT_EPSILON

//コンストラクタ
EnemyCommandStraight::EnemyCommandStraight(const EnemyBasePtr& enemy, const FourDirection front)
	: EnemyCommandBase(enemy)
	, m_NextTargetPos(GSVECTOR2_ZERO)
	, m_CurFront(front) {
	SetNextTargetPos();
}

//更新
void EnemyCommandStraight::Update(float deltaTime) {
	//目標地点までの距離
	m_Velocity = m_NextTargetPos - p_Enemy->getPosition();
	//目標地点にたどり着いているか
	if (m_Velocity.length() <= FLOAT_EPSILON) {
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
	//エネミー本体の座標
	GSvector2 pos = p_Enemy->getPosition();
	//マップ
	Map& map = p_Enemy->getWorld()->GetMap();
	//自分+背面のマス数
	int backChipNum;
	//正面進行方向の配列の作成
	std::vector<int> line;
	switch (m_CurFront.name)
	{
	case FourDirectionName::Up:
		//縦軸Map配列
		line = map.GetRow(pos);
		//逆順に整理
		std::reverse(begin(line), end(line));
		//自分を含めない上からのマス数
		backChipNum = pos.y / CHIP_SIZE;
		//自分を含めた背面のマス数
		backChipNum = map.GetHeight() - backChipNum;
		break;

	case FourDirectionName::Down:
		//縦軸Map配列
		line = map.GetRow(pos);
		//自分を含めた上からのマス数
		backChipNum = pos.y / CHIP_SIZE + 1;
		break;

	case FourDirectionName::Left:
		//横軸Map配列
		line = map.GetColumn(pos);
		//逆順に整理
		std::reverse(begin(line), end(line));
		//自分を含めない左からのマス数
		backChipNum = pos.x / CHIP_SIZE;
		//自分を含めた背面のマス数
		backChipNum = map.GetWidth() - backChipNum;
		break;

	case FourDirectionName::Right:
		//横軸Map配列
		line = map.GetColumn(pos);
		//自分を含めた左からのマス数
		backChipNum = pos.x / CHIP_SIZE + 1;
		break;

	default:
		return;
	}

	//進行可能マス数
	int chipNum = 0;

	//正面何マス目まで進めるか
	for (int i = 0; i < line.size(); i++)
	{
		//背面のマスは無視
		if (backChipNum > i)
			continue;

		//壁マスか
		if (line[i] == 1)
			break;

		else
			chipNum++;
	}

	//進行ベクトル
	GSvector2 frontVector = m_CurFront.GetVector2()*CHIP_SIZE*chipNum;
	//次の目標地点の設定
	m_NextTargetPos = pos + frontVector;
}