//#include "MatCnvTxt.h"
//#include <fstream>
//#include <opencv2\/opencv.hpp>
//
////txtファイルに書き込み
//bool MatCnvTxt::WriteText(const std::string fileName, const cv::Mat & mat){
//	std::string line;
//	std::ofstream ofs(fileName.c_str());
//	//ファイル読み込み失敗
//	if (!ofs)
//	{
//		std::cout << "cannot openfile" << fileName.c_str() << std::endl;
//		return false;
//	}
//	for (int i = 0; i < mat.rows; i++)
//	{
//		for (int j = 0; j < mat.cols; j++)
//		{
//			ofs << mat(i,j);
//			if (i < mat.cols - 1) ofs << "";
//		}
//	}
//}
