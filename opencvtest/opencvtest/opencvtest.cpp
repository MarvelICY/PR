// opencvtest.cpp : �������̨Ӧ�ó������ڵ㡣
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
	imshow("pp������",img);
	waitKey();

	return 0;

}

