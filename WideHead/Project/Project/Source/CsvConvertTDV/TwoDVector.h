#ifndef TwoDVector_H_
#define TwoDVector_H_

#include <vector>

//csv�񎟌��z��
using CsvCellNumber = int;					//Csv�P�}�X�̃f�[�^
using Column = std::vector<CsvCellNumber>;	//�����̃f�[�^
using TwoDVector = std::vector<Column>;		//csv�̃f�[�^

#endif