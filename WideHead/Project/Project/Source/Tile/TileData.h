#ifndef TILE_DATA_H_
#define TILE_DATA_H_

#include<gslib.h>
#include"../Map/TerrainName.h"

class TileData
{
public:
	//コンストラクタ
	TileData();
	//タイル中心座標
	GSvector2 Position();
	//矩形の取得
	GSrect Rectangle();
	//地形情報
	TerrainName GetTerrainName();
public:
	GSvector2 position;
	GSrect rectangle;
	TerrainName terrainName;
};

#endif // !TILE_DATA_H_