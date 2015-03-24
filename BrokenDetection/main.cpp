#include "common.h"

int main(void)
{
	std::string filename = "./sample/a1.jpg";
	cv::Mat img = cv::imread(filename, 0);
	cv::namedWindow("Original Image");
	cv::imshow("Original Image",img);

	//cv::Mat result1;
	//cv::blur(img,result1,cv::Size(5,5));
	//cv::namedWindow("Blur Image");
	//cv::imshow("Blur Image",result1);

	cv::Mat result2;
	cv::GaussianBlur(img,result2,cv::Size(5,5),1.5);
	cv::namedWindow("Gaussian filtered Image");
	cv::imshow("Gaussian filtered Image",result2);

	//cv::Mat result3;
	//cv::medianBlur(img,result3,5);
	//cv::namedWindow("Median Image");
	//cv::imshow("Median Image",result3);

	cv::Mat sobelX;
	cv::Sobel(result2,sobelX,CV_8U,1,0,3,0.4,128);
	cv::Mat sobelY;
	cv::Sobel(result2,sobelY,CV_8U,0,1,3,0.4,128);
	cv::Sobel(result2,sobelX,CV_16S,1,0);
	cv::Sobel(result2,sobelY,CV_16S,0,1);
	cv::Mat sobel;
	sobel=abs(sobelX)+abs(sobelY);
	double sobmin,sobmax;
	cv::minMaxLoc(sobel,&sobmin,&sobmax);
	//std::cout<<""
	cv::Mat sobelImage;
	sobel.convertTo(sobelImage,CV_8U,-255./sobmax,255);
	cv::namedWindow("Sobel Image");
	cv::imshow("Sobel Image",sobelImage);

	cv::Mat sobelThresholded;
	cv::threshold(sobelImage,sobelThresholded,190,255,cv::THRESH_BINARY);
	cv::namedWindow("Threshold Image");
	cv::imshow("Threshold Image",sobelThresholded);

	//cv::Mat image;
	//cv::cvtColor(result2,image,CV_BGR2GRAY);
	cv::Mat contours;
	cv::Canny(result2,contours,125,350);
	cv::Mat contoursInv;
	cv::threshold(contours,contoursInv,200,255,cv::THRESH_BINARY_INV);
	cv::namedWindow("Canny Contours");
	cv::imshow("Canny Contours",contoursInv);

	cv::waitKey();
}