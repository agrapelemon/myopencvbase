#include <opencv2/highgui/highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\opencv.hpp>
#include<vector>
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
	if (true)//显示图片
	{
		//Mat image = imread("F:\\360云盘\\图片\\手机\\刘大勤\\mmexport1518936966633.jpg");  //载入原图
		//Mat image = imread("F:\\360云盘\\图片\\手机\\刘大勤\\mmexport1518936966633.jpg",2|4);  //载入无损的原图像
		//Mat image = imread("F:\\360云盘\\图片\\手机\\刘大勤\\mmexport1518936966633.jpg", 0);  //载入灰度图
		Mat image = imread("F:\\360云盘\\图片\\手机\\刘大勤\\mmexport1518936966633.jpg", 199);  //载入3通道的彩色图像
		imshow("显示图像", image);
	}
	waitKey(0);
	return 0;
}