#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;
/////////////////// Color Detection /////////////// 

int hmin =0, smin = 0, vmin =0;
int hmax = 179, smax = 255, vmax = 255;
Mat imgHSV, mask;
int main(){
    string path = "/home/zjt/Desktop/opencv_learning/Resources/shapes.png";
    Mat img =imread(path);
    

    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    namedWindow("TrackBars", (640, 200));
    createTrackbar("Hue Min", "TrackBars", &hmin, 179); //(色调 色相)
    createTrackbar("Hue Max", "TrackBars", &hmax, 179);
    createTrackbar("Sat Min", "TrackBars", &smin, 255); //(饱和度， 色彩纯净度)
    createTrackbar("Sat Max", "TrackBars", &smax, 255);
    createTrackbar("Val Min", "TrackBars", &vmin, 255); //(明度)
    createTrackbar("Val Max", "TrackBars", &vmax, 255);
    
    while(true){
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);
        inRange(imgHSV, lower, upper, mask);
        imshow("Image", img);
        imshow("img HSV", imgHSV);
        imshow("Image mask", mask);
        waitKey(1);
    }
    return 0;
}