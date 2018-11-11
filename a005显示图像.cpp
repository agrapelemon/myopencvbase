#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	if (true)//显示图像
	{
		Mat image = imread("F:\\QQ图片20170217213022.png");  //存放自己图像的路径 
		imshow("显示图像", image);
	}
	waitKey(0);
	return 0;
}