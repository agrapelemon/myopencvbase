#include <opencv2/highgui/highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\opencv.hpp>
#include<vector>
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
	if (true)//打印mat
	{
		Mat M(2,2,CV_8UC3,Scalar(0,0,255));
		cout << "M = " << endl << " " << M << endl << endl;
	}
	if (true)//颜色转换
	{
		Mat srcImage = imread("F:\\360云盘\\图片\\手机\\刘大勤\\mmexport1518936966633.jpg", 1),dstImage; 
		cvtColor(srcImage, dstImage, COLOR_BGR2Lab);
		imshow("原图", srcImage);
		imshow("颜色转换", dstImage);
	}
	waitKey(0);
	return 0;
}