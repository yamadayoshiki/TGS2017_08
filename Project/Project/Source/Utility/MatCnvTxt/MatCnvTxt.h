#ifndef MATCNVTXT_H_
#define MATCNVTXT_H_
#include <iostream>
namespace cv
{
	class Mat;
}
//cv::Mat�f�[�^�ƃt�@�C���̕ϊ�

namespace MatCnvTxt
{
	//txt�t�@�C���ɏ�������
	bool WriteText(
		const std::string fileName,
		const cv::Mat& mat);

	//txt�t�@�C������ǂݍ���

}


#endif // !MATCNVTXT_H_
