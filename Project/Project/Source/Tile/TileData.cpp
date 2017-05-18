#include "TileData.h"

#include<gslib.h>

TileData::TileData()
{

}

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