#ifndef CSVCONVERTTWODVECTOR_H_
#define CSVCONVERTTWODVECTOR_H_

#include <iostream>
#include "TwoDVector.h"
#include "../Map/MapType.h"

struct GSvector2;
struct CsvCellData;

//csvを二次元配列に変換する
namespace CsvConvertTDV
{
	//csvファイルを二次元配列に変換
	TwoDVector GetTwoDVector(const std::string& fileName, int interval);
	//csv座標をGSvector2に変換(中心座標)
	GSvector2 CsvPosCnvVector2(const int x, const int y, const MapType type);
	//巡回csvファイルをcsv座標データ配列に変換
	std::vector<CsvCellData> GetPatrolPos(const std::string& fileName);
	//csv座標データ配列を座標配列(中心座標)へ変換
	std::vector<GSvector2> GetPatrolPosList(const std::vector<CsvCellData> dataList, MapType type);
	//GSvector2をcsv座標に変換
	GSvector2 Vector2CnvCsvPos(const GSvector2 position, const MapType type);
	//指定された座標をセルの中心座標に補正
	GSvector2 GetTilePos(const GSvector2& pos, const MapType type);
}

#endif // !CSVCONVERTTWODVECTOR_H_