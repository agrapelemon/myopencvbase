#include <opencv2/highgui/highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{

	if (true)//canny��Ե���
	{
		Mat srcImage = imread("F:\\360����\\ͼƬ\\�ֻ�\\������\\mmexport1518936966633.jpg");  //����Լ�ͼ���·�� 
		imshow("ԭͼ", srcImage);
		Mat dstImage, edge, grayImage;
		dstImage.create(srcImage.size(), srcImage.type());
		cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
		blur(grayImage, edge, Size(3, 3));
		Canny(edge, edge, 3, 9, 3);
		imshow("canny��Ե���", edge);
		waitKey(0);
	}

	return 0;
}