#ifndef CSVCELLDATA_H_
#define CSVCELLDATA_H_

struct CsvCellData
{
	struct
	{
		int x;			//横軸番号
		int y;			//縦軸番号
		int number;		//番号
	};

	//ソート用比較演算子定義
	bool operator<(const CsvCellData& other) const {
		return this->number < other.number;
	}
};

#endif