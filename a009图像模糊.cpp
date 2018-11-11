#include <opencv2/highgui/highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	if (true)//图像模糊
	{
		Mat srcImage = imread("F:\\QQ图片20170217213022.png");  //存放自己图像的路径 
		imshow("原图", srcImage);
		Mat dstImage;
		blur(srcImage, dstImage, Size(7, 7));
		imshow("图像模糊,均值滤波", dstImage);
		waitKey(0);
	}
	return 0;
}