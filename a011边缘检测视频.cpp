#include <opencv2/highgui/highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	if (true)
	{
		VideoCapture capture("F:\\俄罗斯.mp4");
		Mat edges;
		while (1)
		{
			Mat frame;
			capture >> frame;
			cvtColor(frame, edges, CV_BGR2GRAY);
			blur(edges, edges, Size(7, 7));
			Canny(edges, edges, 0, 30, 3);
			imshow("canny后的视频", edges);
			waitKey(10);
		}
	}
	return 0;
}