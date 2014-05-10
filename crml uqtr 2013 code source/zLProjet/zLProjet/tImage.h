/** tImage.h     ******************/
/**
** Auteur : Marouane El Gharniti
** 
** CRML UQTR Stage 2013
**
** Library OpenCV 2.4.6
**
***********************************/

#pragma once
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\photo\photo.hpp>
#include <math.h>



#define PI 3.14159265


class tImage
{
private:
	static int const maxAT_BINARY_value;

public:
	tImage(void);
	~tImage(void);
	int rayon;
	cv::Mat ThresholdGlobal( cv::Mat, int, int );
	cv::Mat Morphology_Operations( cv::Mat, char, int, int );
	bool shouldIInvertIt( cv::Mat );
	cv::Mat adaptive_Threshold( cv::Mat, int, int );
	std::pair <std::vector<std::vector<cv::Point> >, int> boundingBox( cv::Mat, char );
	cv::Mat contourDrawing( cv::Mat, std::vector<std::vector<cv::Point> >, int , cv::Scalar, int );
	float contour_area( std::vector<std::vector<cv::Point> >, int );
	float calculateAreaInMmSquare( cv::Mat, float, int );
	cv::Mat addBorders( cv::Mat );
	std::pair<cv::Mat, float> traitementImage(cv::Mat, int);

};
