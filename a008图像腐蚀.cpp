#include <opencv2/highgui/highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	if (true)//ͼ��ʴ
	{
		Mat srcImage = imread("F:\\QQͼƬ20170217213022.png");  //����Լ�ͼ���·�� 
		imshow("ԭͼ", srcImage);
		Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
		Mat dstImage;
		erode(srcImage, dstImage, element);
		imshow("��ʴ����", dstImage);
		waitKey(0);
	}
	return 0;
}