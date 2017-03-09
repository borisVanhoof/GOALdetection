// STD
#include <sstream>
#include <iostream>

// OpenCv
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

// ROS
#include "ros/ros.h"
//#include <cv_bridge/cv_bridge.h>

using namespace cv;

int main (int argc, char ** argv)
{
	cv::Mat image;

	if (argc <2)
	{
		ROS_ERROR("not enough arguments.\n");
		return -1;
	}

	printf("%s\n", argv[1]);

	image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
	if(!image.data)
	{	
		ROS_INFO("could not open the image file...\n");
		return -1;
	}
	//cv::resize(image, image, cv::Size(0,0), 0.5, 0.5, CV_INTER_LINEAR);

	// Create gui
	cv::namedWindow("Display window", WINDOW_AUTOSIZE);	

	imshow("Display window", image);
	
	waitKey(0);

	return 0;
}

