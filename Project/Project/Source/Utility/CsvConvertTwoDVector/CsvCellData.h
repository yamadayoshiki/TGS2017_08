#ifndef CSVCELLDATA_H_
#define CSVCELLDATA_H_

struct CsvCellData
{
	struct
	{
		int x;			//�����ԍ�
		int y;			//�c���ԍ�
		int number;		//�ԍ�
	};

	//�\�[�g�p��r���Z�q��`
	bool operator<(const CsvCellData& other) const {
		return this->number < other.number;
	}
};

#endif