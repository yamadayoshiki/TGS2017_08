#ifndef TwoDVector_H_
#define TwoDVector_H_

#include <vector>

//csv二次元配列
using CsvCellNumber = int;					//Csv１マスのデータ
using Column = std::vector<CsvCellNumber>;	//横軸のデータ
using TwoDVector = std::vector<Column>;		//csvのデータ

#endif