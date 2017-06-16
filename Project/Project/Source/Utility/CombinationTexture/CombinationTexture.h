//#include <cv.h>
//#include <cvaux.h>
//#include <highgui.h>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//int cv_output_tangenbetu_file(InputArray src, char* fileName);
//
//int main(int argc, char** argv) {
//	//Mat jpeg1, jpeg2;
//
//	int img_num = argc > 1 ? argc - 1 : 2;
//	vector<Mat> src_img;
//	int total_height;
//	int width;
//	for (int i = 0; i < img_num; i++) {
//		src_img.push_back(imread(argv[i + 1], 1));
//		Mat last = src_img.back();
//		total_height += last.rows;
//			width = last.cols;
//	}
//
//	Mat combined_img(Size(width, total_height), CV_8UC3);
//
//	vector<Mat>::iterator it = src_img.begin(), it_end = src_img.end();
//	Rect roi_rect;
//	int cnt = 0;
//	for (; it != it_end; ++it) {
//		roi_rect.width = it->cols;
//		roi_rect.height = it->rows;
//
//		Mat roi(combined_img, roi_rect);
//		it->copyTo(roi);
//		roi_rect.y += it->rows;
//
//			cnt++;
//	}
//
//
//	// 表示したい場合は以下を有効に。    
//	//namedWindow("combined images", CV_WINDOW_NORMAL);
//	//imshow("Display combined images", combined_img);
//
//	cv_output_tangenbetu_file(combined_img, <出力したいファイル名>);
//
//	waitKey(0);
//
//	return 0;
//}
//
///**
//* ファイルに書き出す
//*/
//int cv_output_tangenbetu_file(InputArray src, char* fileName) {
//	const string file = fileName;
//
//	vector<int> params(2);
//
//	// 品質(0-100) defalt:95
//	params[0] = CV_IMWRITE_JPEG_QUALITY;
//	params[1] = 100;
//	imwrite(file, src, params);
//
//	return 0;
//}