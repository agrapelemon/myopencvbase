//原代码
#include<iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace cv;
using namespace std;

int main()
{
	if (true)//显示摄像头，失败
	{
		VideoCapture capture(0);
		while (capture.isOpened())
		{
			Mat frame;
			capture >> frame;
			imshow("读取视频", frame);
			waitKey(30);//去掉后不能显示
		}
		printf("1234556");
	}
	waitKey();

	return 0;
}
