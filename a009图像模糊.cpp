#include <opencv2/highgui/highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	if (true)//ͼ��ģ��
	{
		Mat srcImage = imread("F:\\QQͼƬ20170217213022.png");  //����Լ�ͼ���·�� 
		imshow("ԭͼ", srcImage);
		Mat dstImage;
		blur(srcImage, dstImage, Size(7, 7));
		imshow("ͼ��ģ��,��ֵ�˲�", dstImage);
		waitKey(0);
	}
	return 0;
}