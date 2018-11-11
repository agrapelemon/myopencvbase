#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	if (true)//显示RTSP
	{
		VideoCapture capture("rtsp://184.72.239.149/vod/mp4://BigBuckBunny_175k.mov");
		while (1)
		{
			Mat frame;
			capture >> frame;
			imshow("读取视频", frame);
			waitKey(30);//去掉后不能显示
		}
	}
	waitKey(0);
	return 0;
}