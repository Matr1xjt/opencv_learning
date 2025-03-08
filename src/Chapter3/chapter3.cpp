#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;
/////////////////// Resize and Crop ///////////////
int main(){
    string path = "/home/zjt/Desktop/opencv_learning/Resources/test.png";

    Mat img = imread(path);
    Mat imgResize, imgCrop;

    //cout << img.size()<< endl;
    resize(img, imgResize, Size(640, 480));

    Rect roi(100,100,300,250);//矩形
    imgCrop = img(roi);

    imshow("Image", img);
    imshow("ImageResize", imgResize);
    imshow("ImageCrop", imgCrop);
    waitKey(0);
    return 0;
}