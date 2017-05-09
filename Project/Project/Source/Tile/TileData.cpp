#include "TileData.h"

#include<gslib.h>

GSvector2 TileData::Position()
{
	return position;
}

GSrect TileData::Rectangle()
{
	return rectangle;
}

int TileData::Flag()
{
	return flag;
}