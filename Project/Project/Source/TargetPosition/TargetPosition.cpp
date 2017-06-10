#include "TargetPosition.h"
#include "../Define/Def_GSvector2.h"
#include "../Map/Map.h"

//コンストラクタ
TargetPosition::TargetPosition(
	const MapPtr& map,
	const TurnDirection turnDirection,
	const MapType type)
	: m_TurnDirection(turnDirection)
	, p_Map(map)
	, m_Type(type) {
	Clear();
}

//デストラクタ
TargetPosition::~TargetPosition() {
	Clear();
}

//次の目的地の取得
GSvector2 TargetPosition::GetNextPos() {
	if (m_List.size() == 0)
		return GSVECTOR2_ZERO;
	return m_List.cbegin()->position;
}

//最後の目的地の取得
GSvector2 TargetPosition::GetLastPos() {
	if (m_List.size() == 0)
		return GSVECTOR2_ZERO;

	return m_List.back().position;
}

//目標地点配列の最初要素の削除
void TargetPosition::Arrival() {
	m_List.erase(m_List.begin());
}

//目的地Listのクリア
void TargetPosition::Clear() {
	m_List.clear();
}

//指定の回転方向順に進めるマスを決定
void TargetPosition::AlongWall(const GSvector2 position, const FourDirection fourDirection) {
	//方向指定がない場合return
	if (m_TurnDirection.name == TurnDirectionName::None)
		return;

	//結果変数
	Move result;
	//自分の周辺のタイルデータ配列
	std::unordered_map<FourDirection, TileData> mapDate
		= p_Map.lock()->GetAroundTile(position, m_Type);
	//進行方向の逆方向に変更
	FourDirection dir = fourDirection;
	dir.TurnOver();
	//タイルのデータ
	TileData data;

	//進行方向が決定するまで
	while (true)
	{
		//90度回転
		dir.Turn(m_TurnDirection.GetReversal());
		//方向に応じたタイルデータの取り出し
		data = mapDate[dir];
		//タイルが壁ではないか
		if (data.Flag() == 0)
			break;
	}
	result.direction = dir;
	result.position = data.Position();

	//進行方向タイルの座標を設定
	m_List.push_back(result);
}

//指定の回転方向順に進めるマスを決定(連続)
void TargetPosition::AlongWall() {
	AlongWall(m_List.back().position, m_List.back().direction);
}

//複製
void TargetPosition::Clone(const TargetPosition& other) {
	m_TurnDirection = other.m_TurnDirection;
	m_List=other.m_List;
	p_Map = other.p_Map;
	m_Type = other.m_Type;
}