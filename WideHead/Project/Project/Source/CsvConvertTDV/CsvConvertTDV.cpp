#include "CsvConvertTDV.h"
#include <GSvector2.h>
#include <algorithm>
#include "CsvCellData.h"
#include "../FileReader/CsvReader.h"
#include "../Define/Def_Nakayama.h"

TwoDVector CsvConvertTDV::GetTwoDVector(const std::string & fileName, int interval) {
	//結果変数
	TwoDVector result;

	// ファイルの読み込み
	CsvReader file(fileName);

	// 行のループ
	for (int i = 0; i < file.rows(); i++) {
		std::vector<int> tmp;

		// 列のループ
		for (int j = 0; j < file.columns(); j++) {
			tmp.push_back(file.geti(i, j));
		}
		result.push_back(tmp);
	}

	return result;
}

GSvector2 CsvConvertTDV::CsvPosCnvVector2(const int x, const int y, const MapType type) {
	//結果変数
	GSvector2 result;
	//1マスの長さ
	int chipSize = CHIP_SIZE*((int)type + 1);
	//マス数
	int chipNum_x = x / ((int)type + 1);
	int chipNum_y = y / ((int)type + 1);

	result.x = chipSize * chipNum_x + chipSize / 2;
	result.y = chipSize * chipNum_y + chipSize / 2;

	return result;
}

std::vector<CsvCellData> CsvConvertTDV::GetPatrolPos(const std::string & fileName) {
	//結果変数
	std::vector<CsvCellData> result;
	//二次元配列の取得
	TwoDVector twoDVector = TwoDVector(GetTwoDVector(fileName, 0));

	//行のループ
	for (int i = 0; i < twoDVector.size(); i++)
	{
		//列のループ
		for (int j = 0; j < twoDVector[i].size(); j++)
		{
			CsvCellNumber csvCellNum = twoDVector[i][j];

			switch (csvCellNum)
			{
			case 0:
				break;

			default:
				result.push_back(CsvCellData{ j,i,csvCellNum });
				break;
			}
		}
	}
	//順番通りにソート
	std::sort(result.begin(), result.end());

	return result;
}

std::vector<GSvector2> CsvConvertTDV::GetPatrolPosList(const std::vector<CsvCellData> dataList, MapType type) {
	//結果変数
	std::vector<GSvector2> result;

	for (auto i = dataList.begin(); i != dataList.end(); i++)
		result.push_back(CsvPosCnvVector2((*i).x, (*i).y, type));

	return result;
}

//GSvector2をcsv座標に変換
GSvector2 CsvConvertTDV::Vector2CnvCsvPos(const GSvector2 position, const MapType type) {
	//1マスの長さ
	int chipSize = CHIP_SIZE*((int)type + 1);
	//結果変数
	GSvector2 result = position;

	int x = result.x / chipSize;
	int y = result.y / chipSize;

	return  GSvector2(x, y);
}

// 指定された座標をセルの中心座標に補正
GSvector2 CsvConvertTDV::GetTilePos(const GSvector2 & pos, const MapType type)
{
	//1マスの幅
	int chipSize = CHIP_SIZE* ((int)type + 1);
	//結果変数
	int x = pos.x / chipSize;
	int y = pos.y / chipSize;

	x = x * chipSize + chipSize / 2;
	y = y * chipSize + chipSize / 2;

	return GSvector2((float)x, (float)y);
}