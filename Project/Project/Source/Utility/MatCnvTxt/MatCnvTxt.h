#ifndef MATCNVTXT_H_
#define MATCNVTXT_H_
#include <iostream>
namespace cv
{
	class Mat;
}
//cv::Matデータとファイルの変換

namespace MatCnvTxt
{
	//txtファイルに書き込み
	bool WriteText(
		const std::string fileName,
		const cv::Mat& mat);

	//txtファイルから読み込み

}


#endif // !MATCNVTXT_H_
