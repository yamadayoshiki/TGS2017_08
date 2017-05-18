#ifndef TILE_DATA_H_
#define TILE_DATA_H_

#include<gslib.h>

class TileData
{
public:
	//コンストラクタ
	TileData();
	//タイル中心座標
	GSvector2 Position();
	//矩形の取得
	GSrect Rectangle();
	//0=空,1=壁
	int Flag();
public:
	GSvector2 position;
	GSrect rectangle;
	int flag;
};

#endif // !TILE_DATA_H_