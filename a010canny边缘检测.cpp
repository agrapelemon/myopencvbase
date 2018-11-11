#include <opencv2/highgui/highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{

	if (true)//canny±ßÔµ¼ì²â
	{
		Mat srcImage = imread("F:\\360ÔÆÅÌ\\Í¼Æ¬\\ÊÖ»ú\\Áõ´óÇÚ\\mmexport1518936966633.jpg");  //´æ·Å×Ô¼ºÍ¼ÏñµÄÂ·¾¶ 
		imshow("Ô­Í¼", srcImage);
		Mat dstImage, edge, grayImage;
		dstImage.create(srcImage.size(), srcImage.type());
		cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
		blur(grayImage, edge, Size(3, 3));
		Canny(edge, edge, 3, 9, 3);
		imshow("canny±ßÔµ¼ì²â", edge);
		waitKey(0);
	}

	return 0;
}