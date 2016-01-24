#ifndef TARGET_DETECTOR_H
#define TARGET_DETECTOR_H

#include "Target.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;

class TargetDetector
{
    public:
        TargetDetector();
        Target* processImage(Mat input);
        Mat getSecrets();
        //thresholds, cannies, contours, filters contours
    private:
        Mat canny(Mat input);
        Mat secretImage;
        Mat originalSecretImage;
        Mat thresholdImage(Mat input, int minHue, int maxHue, int minVal, int maxVal);
        std::vector<std::vector<Point> >  contour(Mat input);
        std::vector<Point> filterContours(std::vector<std::vector<Point> > contours);
};

#endif
