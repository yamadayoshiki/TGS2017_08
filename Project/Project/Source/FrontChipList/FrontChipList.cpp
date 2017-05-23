#include "FrontChipList.h"
#include "../Map/Map.h"
#include <iostream>
#include "../Define/Def_Nakayama.h"

//コンストラクタ
FrontChipList::FrontChipList(
	Map& map,
	const GSvector2 pos,
	const FourDirection front,
	const MapType type)
	: m_Map(map)
	, m_Type(type) {
	SetFrontChipList(pos, front);
}

//デストラクタ
FrontChipList::~FrontChipList() {
}

//前方マスの設定
void FrontChipList::SetFrontChipList(
	const GSvector2 pos,
	const FourDirection front)
{
	//自分+背面のマス数
	int backChipNum = 0;

	switch (front.name)
	{
	case FourDirectionName::Up:
		//縦軸Map配列
		m_List = m_Map.GetRow(pos, m_Type);
		//逆順に整理
		std::reverse(begin(m_List), end(m_List));
		//自分を含めない上からのマス数
		backChipNum = pos.y / (CHIP_SIZE* ((int)m_Type + 1));
		//自分を含めた背面のマス数
		backChipNum = m_Map.GetHeight(m_Type) - backChipNum;
		break;

	case FourDirectionName::Down:
		//縦軸Map配列
		m_List = m_Map.GetRow(pos, m_Type);
		//自分を含めた上からのマス数
		backChipNum = pos.y / (CHIP_SIZE* ((int)m_Type + 1)) + 1;
		break;

	case FourDirectionName::Left:
		//横軸Map配列
		m_List = m_Map.GetColumn(pos, m_Type);
		//逆順に整理
		std::reverse(begin(m_List), end(m_List));
		//自分を含めない左からのマス数
		backChipNum = pos.x / (CHIP_SIZE* ((int)m_Type + 1));
		//自分を含めた背面のマス数
		backChipNum = m_Map.GetWidth(m_Type) - backChipNum;
		break;

	case FourDirectionName::Right:
		//横軸Map配列
		m_List = m_Map.GetColumn(pos, m_Type);
		//自分を含めた左からのマス数
		backChipNum = pos.x / (CHIP_SIZE* ((int)m_Type + 1)) + 1;
		break;

	default:
		break;
	}

	//背面マスの削除
	for (int i = 0; i < backChipNum; i++)
		m_List.erase(m_List.begin());
}

//空きマスの有無
bool FrontChipList::GetSpeaceExist()
{
	for (auto itr = m_List.cbegin(); itr != m_List.cend(); ++itr)
		if (*itr == 0)
			return true;

	return false;
}

//壁マスまでの数
int FrontChipList::GetSpeaceNum()
{
	//結果変数
	int result = 0;
	for (auto itr = m_List.cbegin(); itr != m_List.cend(); ++itr)
	{
		if (*itr == 1)
			break;

		else
			result++;
	}
	return result;
}

//壁の向こう側の空きマスまでの数
int FrontChipList::GeTheOffSideOfTheWallChipNum()
{
	//結果変数
	int result = 0;
	//壁を見つけたか
	bool flag_1 = false;
	//壁越しの空きを見つけたか
	bool flag_2 = false;
	for (auto itr = m_List.cbegin(); itr != m_List.cend(); ++itr)
	{
		//マス加算
		result++;
		//壁か
		if (*itr == 1)
			flag_1 = true;
		//壁越しの空きマスか
		else
			if (flag_1 == true) {
				flag_2 = true;
				break;
			}
	}
	//見つからなかった場合
	if (flag_2 == false)
		result = 0;

	return result;
}
