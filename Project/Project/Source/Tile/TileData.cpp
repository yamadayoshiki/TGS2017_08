#include "TileData.h"

#include<gslib.h>

TileData::TileData() {
}

//タイル中心座標
GSvector2 TileData::Position()
{
	return position;
}

//矩形の取得
GSrect TileData::Rectangle()
{
	return rectangle;
}

//0=空,1=壁
int TileData::Flag()
{
	return flag;
}