#ifndef MAP_H_
#define MAP_H_

#include "../Utility/Rederer2D/Renderer2DPtr.h"
#include "../Utility/FourDirection/FourDirection.h"
#include "../Tile/TileData.h"
#include "../ActorContains/ActorPtr.h"
#include "../Base/GameManagerContains/IGameManagerPtr.h"
#include"../WorldContains/IWorld.h"

#include "MapData.h"
#include "MapType.h"

#include <iostream>
#include <unordered_map>

//グリッド座標
class Point2;

//押し出し結果構造体
struct ResultPushDirection
{
	bool flag;						//押し出されたか
	GSvector2 position;				//結果座標
	FourDirection pushDirection;	//押し出された方向
};

class Map {
public:
	//コンストラクタ
	Map(const IGameManagerPtr& gameManager);
	//描画
	void draw(const MapType& type = MapType::Default);
	//マップの取得
	MapData& getmap(const MapType& type = MapType::Default);
	// マップの登録
	void regist(const MapData& data, const MapType& type = MapType::Default);
	//周りのタイルデータの取得
	std::unordered_map<FourDirection, TileData>GetAroundTile(const GSvector2& position, const MapType& type = MapType::Default);
	//指定された座標の縦軸のブロックの取得
	std::vector<int>GetRow(const GSvector2& position, const MapType& type = MapType::Default);
	//指定された座標の横軸のブロックの取得
	std::vector<int>GetColumn(const GSvector2& position, const MapType& type = MapType::Default);
	//タイルデータの取得
	TileData GetTileData(int column, int row, const MapType& type = MapType::Default);
	// 正面に壁があるか無いか
	bool IsInFrontOfTheWall(const GSvector2& pos, FourDirection direction, const MapType& type = MapType::Default);

	// 押し出し処理
	GSvector2 PushForPlayer(const GSvector2& current_pos, const GSvector2& target_pos);
	// 押し出し処理(マス準拠)
	ResultPushDirection PushForChara(const GSvector2& current_pos, const GSvector2& target_pos, const MapType& charaSize);
	// 指定された座標をタイルの中心座標に補正
	GSvector2 GetTilePos(const GSvector2& pos, const MapType type = MapType::Default);
	//指定されたcsv座標の情報更新
	void SetcsvParameter(GSvector2 position, int parameter, MapType type, IWorld* world);

	//神保
public:
	// データの取得
	int operator [] (const Point2& position) const;
	// 幅の取得
	int GetWidth(const MapType& type = MapType::Default) const;
	// 高さの取得
	int GetHeight(const MapType& type = MapType::Default) const;

private:
	// マップの格納
	std::unordered_map<MapType, MapData> m_Maps;
	//ゲームマネージャーポインタ
	IGameManagerPtr p_GameManager;
};

#endif // !MAP_H_