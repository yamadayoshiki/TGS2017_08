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

//0=��,1=��
int TileData::Flag()
{
	return flag;
}