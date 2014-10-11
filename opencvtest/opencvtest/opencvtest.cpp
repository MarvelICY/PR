// opencvtest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"My World";
	Mat img = imread("F:/test.jpg");
	if(img.empty())
	{
		cout<<"error";
		return -1;
	}
	imshow("pp的靓照",img);
	waitKey();

	return 0;

}

