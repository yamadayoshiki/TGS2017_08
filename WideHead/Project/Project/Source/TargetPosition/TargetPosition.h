#ifndef TARGETPOSITION_H_
#define TARGETPOSITION_H_

#include <vector>
#include <GSvector2.h>
#include "../Utility/FourDirection/FourDirection.h"
#include "../Map/MapPtr.h"
#include "../Map/MapType.h"

//目標地点構造体
struct Move
{
	GSvector2 position;			//目標地点
	FourDirection direction;	//向き
};

//目標地点管理クラス
class TargetPosition
{
public:
	//コンストラクタ
	TargetPosition(
		const MapPtr& map,
		const TurnDirection turnDirection,
		const MapType type);
	//デストラクタ
	~TargetPosition();
	//次の目標地点の取得
	GSvector2 GetNextPos();
	//最後の目標地点の取得
	GSvector2 GetLastPos();
	//目標地点配列の最初要素の削除
	void Arrival();
	//目的地Listのクリア
	void Clear();
	//指定の回転方向順に進めるマスを決定(座標,向き指定)
	void AlongWall(
		const GSvector2 position,
		const FourDirection fourDirection);
	//指定の回転方向順に進めるマスを決定(連続)
	void AlongWall();
	//複製
	void Clone(const TargetPosition& other);

private:
	//回転方向
	TurnDirection m_TurnDirection;
	//目標地点配列
	std::vector<Move> m_List;
	//マップタイプ
	MapType m_Type;
	//マップ
	MapWPtr p_Map;
};

#endif