//ԭ����

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace cv;
using namespace std;

void detectAndDraw(Mat& img, CascadeClassifier& cascade,
	CascadeClassifier& nestedCascade,
	double scale, bool tryflip);

int main()//����ʶ��
{
	//VideoCapture cap(0);    //��Ĭ������ͷ
	//if(!cap.isOpened())
	//{
	//    return -1;
	//}
	Mat frame;
	Mat edges;

	CascadeClassifier cascade, nestedCascade;
	bool stop = false;
	//ѵ���õ��ļ����ƣ������ڿ�ִ���ļ�ͬĿ¼��
	cascade.load("D:\\Program Files\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml");
	nestedCascade.load("D:\\Program Files\\opencv\\sources\\data\\haarcascades\\haarcascade_eye.xml");
	//frame = imread("F:\\360����\\ͼƬ\\�ֻ�\\������\\mmexport1518936966633.jpg");
	frame = imread("F:\\360����\\a05�Լ�����\\a013opencv����\\opencvtest\\x64\\Debug\\1.jpg");
	detectAndDraw(frame, cascade, nestedCascade, 2, 0);
	waitKey();
	/*
	while(!stop)
	{
	cap>>frame;
	detectAndDraw( frame, cascade, nestedCascade,2,0 );
	if(waitKey(30) >=0)
	stop = true;
	}
	*/
	return 0;
}
void detectAndDraw(Mat& img, CascadeClassifier& cascade,
	CascadeClassifier& nestedCascade,
	double scale, bool tryflip)
{
	int i = 0;
	double t = 0;
	//�������ڴ����������������
	vector<Rect> faces, faces2;
	//����һЩ��ɫ��������ʾ��ͬ������
	const static Scalar colors[] = {
		CV_RGB(0,0,255),
		CV_RGB(0,128,255),
		CV_RGB(0,255,255),
		CV_RGB(0,255,0),
		CV_RGB(255,128,0),
		CV_RGB(255,255,0),
		CV_RGB(255,0,0),
		CV_RGB(255,0,255) };
	//������С��ͼƬ���ӿ����ٶ�
	//nt cvRound (double value) ��һ��double�͵��������������룬������һ����������
	Mat gray, smallImg(cvRound(img.rows / scale), cvRound(img.cols / scale), CV_8UC1);
	//ת�ɻҶ�ͼ��Harr�������ڻҶ�ͼ
	cvtColor(img, gray, CV_BGR2GRAY);
	imshow("�Ҷ�", gray);
	//�ı�ͼ���С��ʹ��˫���Բ�ֵ
	resize(gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR);
	imshow("��С�ߴ�", smallImg);
	//�任���ͼ�����ֱ��ͼ��ֵ������
	equalizeHist(smallImg, smallImg);
	imshow("ֱ��ͼ��ֵ����", smallImg);
	//����ʼ�ͽ�������˺�����ȡʱ�䣬������������㷨ִ��ʱ��
	t = (double)cvGetTickCount();
	//�������
	//detectMultiScale������smallImg��ʾ����Ҫ��������ͼ��ΪsmallImg��faces��ʾ��⵽������Ŀ�����У�1.1��ʾ
	//ÿ��ͼ��ߴ��С�ı���Ϊ1.1��2��ʾÿһ��Ŀ������Ҫ����⵽3�β��������Ŀ��(��Ϊ��Χ�����غͲ�ͬ�Ĵ��ڴ�
	//С�����Լ�⵽����),CV_HAAR_SCALE_IMAGE��ʾ�������ŷ���������⣬��������ͼ��Size(30, 30)ΪĿ���
	//��С���ߴ�
	cascade.detectMultiScale(smallImg, faces,
		1.1, 2, 0
		//|CV_HAAR_FIND_BIGGEST_OBJECT
		//|CV_HAAR_DO_ROUGH_SEARCH
		| CV_HAAR_SCALE_IMAGE
		, Size(30, 30));
	//���ʹ�ܣ���תͼ��������
	if (tryflip)
	{
		flip(smallImg, smallImg, 1);
		imshow("��תͼ��", smallImg);
		cascade.detectMultiScale(smallImg, faces2,
			1.1, 2, 0
			/*|CV_HAAR_FIND_BIGGEST_OBJECT
			|CV_HAAR_DO_ROUGH_SEARCH*/
			| CV_HAAR_SCALE_IMAGE
			, Size(30, 30));
		for (vector<Rect>::const_iterator r = faces2.begin(); r != faces2.end(); r++)
		{
			faces.push_back(Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height));
		}
	}
	t = (double)cvGetTickCount() - t;
	//   qDebug( "detection time = %g ms\n", t/((double)cvGetTickFrequency()*1000.) );
	for (vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); r++, i++)
	{
		Mat smallImgROI;
		vector<Rect> nestedObjects;
		Point center;
		Scalar color = colors[i % 8];
		int radius;

		double aspect_ratio = (double)r->width / r->height;
		if (0.75 < aspect_ratio && aspect_ratio < 1.3)
		{
			//��ʾ����ʱ����С֮ǰ��ͼ���ϱ�ʾ����������������ű��������ȥ
			center.x = cvRound((r->x + r->width*0.5)*scale);
			center.y = cvRound((r->y + r->height*0.5)*scale);
			radius = cvRound((r->width + r->height)*0.25*scale);
			circle(img, center, radius, color, 3, 8, 0);
		}
		else
			rectangle(img, cvPoint(cvRound(r->x*scale), cvRound(r->y*scale)),
				cvPoint(cvRound((r->x + r->width - 1)*scale), cvRound((r->y + r->height - 1)*scale)),
				color, 3, 8, 0);
		if (nestedCascade.empty())
			continue;
		smallImgROI = smallImg(*r);
		//ͬ�������������
		nestedCascade.detectMultiScale(smallImgROI, nestedObjects,
			1.1, 2, 0
			//|CV_HAAR_FIND_BIGGEST_OBJECT
			//|CV_HAAR_DO_ROUGH_SEARCH
			//|CV_HAAR_DO_CANNY_PRUNING
			| CV_HAAR_SCALE_IMAGE
			, Size(30, 30));
		for (vector<Rect>::const_iterator nr = nestedObjects.begin(); nr != nestedObjects.end(); nr++)
		{
			center.x = cvRound((r->x + nr->x + nr->width*0.5)*scale);
			center.y = cvRound((r->y + nr->y + nr->height*0.5)*scale);
			radius = cvRound((nr->width + nr->height)*0.25*scale);
			circle(img, center, radius, color, 3, 8, 0);
		}
	}
	namedWindow("ʶ����", CV_WINDOW_NORMAL);
	imshow("ʶ����", img);
}
