#include <opencv2/highgui/highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\opencv.hpp>
#include<vector>
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
	if (true)//��ʾͼƬ
	{
		//Mat image = imread("F:\\360����\\ͼƬ\\�ֻ�\\������\\mmexport1518936966633.jpg");  //����ԭͼ
		//Mat image = imread("F:\\360����\\ͼƬ\\�ֻ�\\������\\mmexport1518936966633.jpg",2|4);  //���������ԭͼ��
		//Mat image = imread("F:\\360����\\ͼƬ\\�ֻ�\\������\\mmexport1518936966633.jpg", 0);  //����Ҷ�ͼ
		Mat image = imread("F:\\360����\\ͼƬ\\�ֻ�\\������\\mmexport1518936966633.jpg", 199);  //����3ͨ���Ĳ�ɫͼ��
		imshow("��ʾͼ��", image);
	}
	waitKey(0);
	return 0;
}