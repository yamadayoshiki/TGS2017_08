#ifndef TILE_DATA_H_
#define TILE_DATA_H_

#include<gslib.h>

class TileData
{
public:
	//�R���X�g���N�^
	TileData();
	//�^�C�����S���W
	GSvector2 Position();
	//��`�̎擾
	GSrect Rectangle();
	//0=��,1=��
	int Flag();
public:
	GSvector2 position;
	GSrect rectangle;
	int flag;
};

#endif // !TILE_DATA_H_