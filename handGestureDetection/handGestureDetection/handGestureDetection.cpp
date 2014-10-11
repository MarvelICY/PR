#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void detectAndDisplay( Mat frame );

String face_cascade_name = "hand.xml";
CascadeClassifier CHandCascade;
string window_name = "Hand Gesture Detection";

int main(int argc, const char** argv)
{
	Mat frame;

	if( !CHandCascade.load( face_cascade_name ) )
	{
		printf("--(!)Error loading\n");
		getchar();
		return -1;
	}

	CvCapture* capture = cvCaptureFromCAM(0);

	if(capture)
	{
		while( true )
		{
			frame = cvQueryFrame( capture );
			if( !frame.empty() )
			{ 
				detectAndDisplay( frame );
			}
			else
			{
				continue; 
			}

			int c = waitKey(10);
			if((char)c == 27)
			{
				break;
			} 

		}
	}
	return 0;
}


void detectAndDisplay( Mat frame )
{
	std::vector<Rect> hands;
	Mat frame_gray;
	cvtColor( frame, frame_gray, CV_BGR2GRAY );
	equalizeHist( frame_gray, frame_gray );
	CHandCascade.detectMultiScale(frame_gray, hands, 1.1, 2, CV_HAAR_DO_CANNY_PRUNING, Size(75, 75));

	for(size_t i=0; i<hands.size(); i++)
	{
		if(hands[i].width>100&&hands[i].height>100)
		{
		rectangle(frame, hands[i], Scalar(255,0,255));
		}
	} 
	imshow( window_name, frame );
}