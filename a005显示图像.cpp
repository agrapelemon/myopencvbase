#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	if (true)//��ʾͼ��
	{
		Mat image = imread("F:\\QQͼƬ20170217213022.png");  //����Լ�ͼ���·�� 
		imshow("��ʾͼ��", image);
	}
	waitKey(0);
	return 0;
}