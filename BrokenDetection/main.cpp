#include "common.h"

int main(void)
{
	std::string filename = "./sample/a1.jpg";
	cv::Mat img = cv::imread(filename, 0);
	cv::imshow("img",img);
	cv::waitKey();
}