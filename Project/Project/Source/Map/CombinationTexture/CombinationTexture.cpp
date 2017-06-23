#include "CombinationTexture.h"
#include <opencv2/core/core.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "../../Map/TerrainName.h"
#include <string>

void CombinationTexture::CreateMapImg(
	const CsvTwoDVectorTerrainData & data,
	const char* fileName) {
	cv::Mat rows[30];
	for (int i = 0; i < 30; i++)
		rows[i] = CreateRow(data[i], fileName);

	cv::Mat result;
	cv::vconcat(rows, 30, result);
	cv::imwrite("Resource/Texture/Stage.png", result);
}

cv::Mat CombinationTexture::CreateRow(
	const CsvRowTerrainData & data,
	const std::string & fileName) {
	//‰æ‘œ‚Ì“Ç‚Ýž‚Ý
	const cv::Mat img = cv::imread(fileName, -1);

	//“§–¾‚Ì“Ç‚Ýž‚Ý
	const cv::Mat alpha = cv::imread("Resource/Texture/Speace.png", -1);

	//‰¡”z—ñ
	cv::Mat row[40];
	for (int i = 0; i < 40; i++)
		row[i] = data[i] != TerrainName::Wall ? alpha : img;

	cv::Mat resultRow;
	cv::hconcat(row, 40, resultRow);

	return resultRow;
}