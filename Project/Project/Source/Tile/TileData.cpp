#include "TileData.h"

#include<gslib.h>

TileData::TileData() {
}

//�^�C�����S���W
GSvector2 TileData::Position()
{
	return position;
}

//��`�̎擾
GSrect TileData::Rectangle()
{
	return rectangle;
}

//�n�`���
TerrainName TileData::GetTerrainName()
{
	return terrainName;
}