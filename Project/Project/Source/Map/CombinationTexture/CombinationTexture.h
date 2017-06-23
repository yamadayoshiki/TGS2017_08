#ifndef COMBINATIONTEXTURE_H_
#define COMBINATIONTEXTURE_H_


#include "../../Map/CsvTwoDVectorTerrainData.h"

#include <iostream>
#include<opencv2\opencv.hpp>

//‰æ‘œŒ‹‡
namespace CombinationTexture
{
	//“ñŸŒ³”z—ñ
	void CreateMapImg(
		const CsvTwoDVectorTerrainData& data,
		const char* fileName);

	//ˆêŸŒ³”z—ñ(‰¡)
	cv::Mat CreateRow(
		const CsvRowTerrainData& data,
		const std::string& fileName);
};
#endif // !COMBINATIONTEXTURE_H_
