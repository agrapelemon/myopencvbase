#include <opencv2/highgui/highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	if (true)//Í¼Ïñ¸¯Ê´
	{
		Mat srcImage = imread("F:\\QQÍ¼Æ¬20170217213022.png");  //´æ·Å×Ô¼ºÍ¼ÏñµÄÂ·¾¶ 
		imshow("Ô­Í¼", srcImage);
		Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
		Mat dstImage;
		erode(srcImage, dstImage, element);
		imshow("¸¯Ê´²Ù×÷", dstImage);
		waitKey(0);
	}
	return 0;
}