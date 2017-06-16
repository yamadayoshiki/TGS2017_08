#ifndef FRONTCHIPLIST_H_
#define FRONTCHIPLIST_H_

#include <vector>
#include "../Map/MapType.h"
#include <GSvector2.h>
#include "../Utility/FourDirection/FourDirection.h"
#include "../Map/MapPtr.h"
enum class TerrainName;

//前方マスクラス
class FrontChipList
{
public:
	//コンストラクタ
	FrontChipList(
		const MapPtr& map,
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
	//壁に直接触れるまでの距離の長さ
	float GetToWallLength(const GSvector2 pos, const FourDirection direction, const float width);

private:
	MapWPtr p_Map;							//マップ
	std::vector<TerrainName> m_List;		//前方マスList
	MapType m_Type;							//マップタイプ
	FourDirection m_FrontDirection;			//向き
};

#endif