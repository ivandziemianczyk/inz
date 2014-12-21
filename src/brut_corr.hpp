/*
 * brut_corr.hpp
 *
 *  Created on: Sep 9, 2014
 *      Author: ivan
 */

#ifndef BRUT_CORR_HPP_
#define BRUT_CORR_HPP_


#include "opencv2\highgui\highgui.hpp"
#include "opencv2\core\core.hpp"
#include "opencv2\imgproc\imgproc.hpp"
#include "opencv2\contrib\contrib.hpp"

#include <iostream>

using namespace std;
using namespace cv;

//w programie jest duzo spradzen i warunkow.
//W wersji ostatecznej mozna robic
//wszystkie sprawdzenia na poczatku za jednym razem
//Operating on float type. Final Mat image of type CV_32F
class BrutCorr{

public:
	BrutCorr(){}//setZero();}
	void setParameters(Mat&, Mat&,size_t subImg, size_t patch);
	void correlate();

private:
	void setZero();
	float getMediumValueAroundPoint(Mat&, Point);
	float getStDeviationValueAroundPoint(Mat&, Point);
	float getStDeviationValueAroundPoint(Mat&, Point, float mediumValue);
	float getCorrelate(Point p1, Point p2);
	float getBestCorrFromArea(Point);

private:
	Mat m_img1;
	Mat m_img2;
	Mat m_corrImg;
	int m_patch;
	int m_subImg;
};


#endif /* BRUT_CORR_HPP_ */