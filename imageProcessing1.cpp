
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <conio.h>
#include <iostream>

using namespace std;
using namespace cv;



Mat imgCreated(350, 350, CV_8UC1, Scalar(70));

void mouse_click(int event, int x, int y, int flags, void *param)
{
	Mat img2; imgCreated.copyTo(img2);
	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
	{
		Rect myrect(x - 32, y - 32, 64, 64);
		Rect imgBounds(0, 0, img2.cols, img2.rows);
		myrect = myrect & imgBounds;

		rectangle(img2, myrect, Scalar(0, 255, 0), 4);

		imgCreated(myrect) += 20;
		imshow("Image", imgCreated);
	}
	break;
	case CV_EVENT_RBUTTONDOWN:
	{
		Rect myrect(x - 32, y - 32, 64, 64);
		Rect imgBounds(0, 0, img2.cols, img2.rows);
		myrect = myrect & imgBounds;

		rectangle(img2, myrect, Scalar(0, 255, 0), 4);

		imgCreated(myrect) -= 20;
		imshow("Image", imgCreated);

	}
	break;
	}
}


int main(int argc, char** argv)
{
	Mat img;
	img = imread("lenna.png", CV_LOAD_IMAGE_GRAYSCALE);
	imgCreated = img;
	namedWindow("Image", WINDOW_NORMAL | WINDOW_KEEPRATIO);
	imshow("Image", imgCreated);
	cvSetMouseCallback("Image", mouse_click, 0);

	while (cv::waitKey(1) != 27);

	return 0;
}





