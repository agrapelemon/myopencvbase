#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	if (true)//显示文件视频
	{
		VideoCapture capture("F:\\俄罗斯.mp4");
		while (1)
		{
			Mat frame;
			capture >> frame;
			imshow("读取视频", frame);
			waitKey(30);
		}
	}
	waitKey(0);
	return 0;
}