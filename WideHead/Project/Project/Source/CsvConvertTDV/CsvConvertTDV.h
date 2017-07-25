#ifndef CSVCONVERTTWODVECTOR_H_
#define CSVCONVERTTWODVECTOR_H_

#include <iostream>
#include "TwoDVector.h"
#include "../Map/MapType.h"

struct GSvector2;
struct CsvCellData;

//csv��񎟌��z��ɕϊ�����
namespace CsvConvertTDV
{
	//csv�t�@�C����񎟌��z��ɕϊ�
	TwoDVector GetTwoDVector(const std::string& fileName, int interval);
	//csv���W��GSvector2�ɕϊ�(���S���W)
	GSvector2 CsvPosCnvVector2(const int x, const int y, const MapType type);
	//����csv�t�@�C����csv���W�f�[�^�z��ɕϊ�
	std::vector<CsvCellData> GetPatrolPos(const std::string& fileName);
	//csv���W�f�[�^�z������W�z��(���S���W)�֕ϊ�
	std::vector<GSvector2> GetPatrolPosList(const std::vector<CsvCellData> dataList, MapType type);
	//GSvector2��csv���W�ɕϊ�
	GSvector2 Vector2CnvCsvPos(const GSvector2 position, const MapType type);
	//�w�肳�ꂽ���W���Z���̒��S���W�ɕ␳
	GSvector2 GetTilePos(const GSvector2& pos, const MapType type);
}

#endif // !CSVCONVERTTWODVECTOR_H_