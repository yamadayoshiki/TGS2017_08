#ifndef FRONTCHIPLIST_H_
#define FRONTCHIPLIST_H_

#include <vector>
#include "../Map/MapType.h"
#include <GSvector2.h>
#include "../Utility/FourDirection/FourDirection.h"
class Map;

//前方マスクラス
class FrontChipList
{
public:
	//コンストラクタ
	FrontChipList(
		Map& map, 
		const GSvector2 pos, 
		const FourDirection front,
		const MapType type = MapType::Default);
	//デストラクタ
	~FrontChipList();
	//前方マスの設定
	void SetFrontChipList(const GSvector2 pos, const FourDirection front);
	//空きマスの有無
	bool GetSpeaceExist();
	//壁マスまでの数
	int GetSpeaceNum();
	//壁の向こう側の空きマスまでの数
	int GeTheOffSideOfTheWallChipNum();

private:
	Map& m_Map;					//マップ
	std::vector<int> m_List;	//前方マスList
	MapType m_Type;				//マップタイプ
};

#endif