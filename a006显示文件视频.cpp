#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	if (true)//��ʾ�ļ���Ƶ
	{
		VideoCapture capture("F:\\����˹.mp4");
		while (1)
		{
			Mat frame;
			capture >> frame;
			imshow("��ȡ��Ƶ", frame);
			waitKey(30);
		}
	}
	waitKey(0);
	return 0;
}