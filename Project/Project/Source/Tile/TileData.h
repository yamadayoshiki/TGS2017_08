#ifndef TILE_DATA_H_
#define TILE_DATA_H_

#include<gslib.h>

class TileData
{
public:
	//�R���X�g���N�^
	TileData();
	//���W
	GSvector2 Position();
	//��`
	GSrect Rectangle();
	//�t���O
	int Flag();

	GSvector2 position;
	GSrect rectangle;
	int flag;
};

#endif // !TILE_DATA_H_