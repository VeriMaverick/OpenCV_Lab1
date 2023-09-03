#include "iostream"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;


int main()
{
	VideoCapture cap(0);//创建一个VideoCapture对象用于打开摄像头0
	if (!cap.isOpened())//判断是否打开成功
	{
		cout << "Error: Cannot open the video camera." << endl;
		return -1;
	}

	Mat frame;//创建一个Mat对象，用于存储每一帧的图像
	Mat edges;//创建一个Mat对象，用于存储每一帧的图像的边缘图像

	bool stop = false;//用于判断是否停止读取图像

	while (!stop)
	{
		cap >> frame;//读取当前帧的图像存放到frame中
		//uchar b = frame.at<Vec3b>(0, 0)[0];
		//uchar g = frame.at<Vec3b>(0, 0)[1];
		//uchar r = frame.at<Vec3b>(0, 0)[2];
		//cout << "b=" << (int)b << " g=" << (int)g << " r=" << (int)r << endl;
		


		//修改像素值
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				frame.at<Vec3b>(i + 100, j + 100)[0] = 255;
				frame.at<Vec3b>(i + 100, j + 100)[1] = 0;
				frame.at<Vec3b>(i + 100, j + 100)[2] = 255;
			}
		}
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 60; j++)
			{
				frame.at<Vec3b>(i + 140, j + 120)[0] = 255;
				frame.at<Vec3b>(i + 140, j + 120)[1] = 0;
				frame.at<Vec3b>(i + 140, j + 120)[2] = 255;
			}
		}
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 120; j++)
			{
				frame.at<Vec3b>(i + 180, j + 90)[0] = 255;
				frame.at<Vec3b>(i + 180, j + 90)[1] = 0;
				frame.at<Vec3b>(i + 180, j + 90)[2] = 255;
			}
		}
		for (int i = 0; i < 80; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				frame.at<Vec3b>(i + 110, j + 140)[0] = 255;
				frame.at<Vec3b>(i + 110, j + 140)[1] = 0;
				frame.at<Vec3b>(i + 110, j + 140)[2] = 255;
			}
		}
		imshow("Camera", frame);//显示当前帧的图像
		if (waitKey(30) >= 0) stop = true;//按下任意键停止读取图像
	}
	return 0;
}