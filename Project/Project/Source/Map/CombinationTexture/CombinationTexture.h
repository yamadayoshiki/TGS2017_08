#ifndef COMBINATIONTEXTURE_H_
#define COMBINATIONTEXTURE_H_


#include "../../Map/CsvTwoDVectorTerrainData.h"

#include <vector>
#include <iostream>
#include<opencv2\opencv.hpp>

//�摜����
namespace CombinationTexture
{
	/* �O���b�h��ɉ摜��z�u */
	//�񎟌��z��
	void CreateMapImg(
		const CsvTwoDVectorTerrainData& data,
		const char* fileName);

	//�ꎟ���z��(��)
	cv::Mat CreateRow(
		const CsvRowTerrainData& data,
		const std::string& fileName);

	//�ꎟ���z��(�c)
	cv::Mat CreateColumn(
		const std::vector<int> data,
		const std::string);

};
#endif // !COMBINATIONTEXTURE_H_
