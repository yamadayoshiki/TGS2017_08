#ifndef COMBINATIONTEXTURE_H_
#define COMBINATIONTEXTURE_H_


#include "../../Map/CsvTwoDVectorTerrainData.h"

#include <iostream>
#include<opencv2\opencv.hpp>

//�摜����
namespace CombinationTexture
{
	//�񎟌��z��
	void CreateMapImg(
		const CsvTwoDVectorTerrainData& data,
		const char* fileName);

	//�ꎟ���z��(��)
	cv::Mat CreateRow(
		const CsvRowTerrainData& data,
		const std::string& fileName);
};
#endif // !COMBINATIONTEXTURE_H_
