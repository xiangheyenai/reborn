#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,char **argv)
{
	Mat img;
	img = imread("nilu.jpeg");
	if (img.empty())
	{
		cout << "请确认图像文件名称是否正确" << endl;
		return -1;
	}
	imshow("test", img);
	waitKey(0);
	return 0;
}