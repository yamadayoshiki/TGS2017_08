#include <iostream>
#include<GSvector2.h>
#include "../FileReader/CsvReader.h"
#include"../Define/Def_Nakayama.h"
#include"MapGenerator.h"


//�R���X�g���N�^
MapGenerator::MapGenerator(const std::string& file_name){
	load(file_name);
}

//�t�@�C���̓ǂݍ���
void MapGenerator::load(const std::string& file_name)
{
	CsvReader file = CsvReader(file_name);

	for (int i = 0; i < file.rows(); i++)
	{
		for (int j = 0; j < file.columns(); j++)
		{
			std::cout << file.get(i, j);
		}
		std::cout << "\n";
	}

	for (int i = 0; i < file.rows(); i++)
	{
		for (int j = 0; j < file.columns(); j++)
		{
			if (file.geti(i, j) == 1)
			{
				GSvector2(j, i) * CHIP_SIZE;
			}
			std::cout << file.get(i, j);
		}
		std::cout << "\n";
	}
}
