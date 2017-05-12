#ifndef TILE_DATA_H_
#define TILE_DATA_H_

#include<gslib.h>

class TileData
{
public:
	//コンストラクタ
	TileData();
	//座標
	GSvector2 Position();
	//矩形
	GSrect Rectangle();
	//フラグ
	int Flag();

	GSvector2 position;
	GSrect rectangle;
	int flag;
};

#endif // !TILE_DATA_H_