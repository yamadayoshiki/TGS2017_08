#ifndef COMBINATIONTEXTURE_H_
#define COMBINATIONTEXTURE_H_


#include "../../Map/CsvTwoDVectorTerrainData.h"

#include <iostream>
#include<opencv2\opencv.hpp>

//画像結合
namespace CombinationTexture
{
	//二次元配列
	void CreateMapImg(
		const CsvTwoDVectorTerrainData& data,
		const char* fileName);

	//一次元配列(横)
	cv::Mat CreateRow(
		const CsvRowTerrainData& data,
		const std::string& fileName);
};
#endif // !COMBINATIONTEXTURE_H_
