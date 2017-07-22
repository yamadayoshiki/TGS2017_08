#ifndef TILE_DATA_H_
#define TILE_DATA_H_

#include<gslib.h>
#include"../Map/TerrainName.h"

class TileData
{
public:
	//�R���X�g���N�^
	TileData();
	//�^�C�����S���W
	GSvector2 Position();
	//��`�̎擾
	GSrect Rectangle();
	//�n�`���
	TerrainName GetTerrainName();
public:
	GSvector2 position;
	GSrect rectangle;
	TerrainName terrainName;
};

#endif // !TILE_DATA_H_