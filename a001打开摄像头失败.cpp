//ԭ����
#include<iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace cv;
using namespace std;

int main()
{
	if (true)//��ʾ����ͷ��ʧ��
	{
		VideoCapture capture(0);
		while (capture.isOpened())
		{
			Mat frame;
			capture >> frame;
			imshow("��ȡ��Ƶ", frame);
			waitKey(30);//ȥ��������ʾ
		}
		printf("1234556");
	}
	waitKey();

	return 0;
}
