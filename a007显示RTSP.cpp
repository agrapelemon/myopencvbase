#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	if (true)//��ʾRTSP
	{
		VideoCapture capture("rtsp://184.72.239.149/vod/mp4://BigBuckBunny_175k.mov");
		while (1)
		{
			Mat frame;
			capture >> frame;
			imshow("��ȡ��Ƶ", frame);
			waitKey(30);//ȥ��������ʾ
		}
	}
	waitKey(0);
	return 0;
}