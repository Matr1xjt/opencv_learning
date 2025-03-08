#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;
///////////////// basic function ////////////////////
int main(){
    string path = "/home/zjt/Desktop/opencv_learning/Resources/test.png";
    Mat img = imread(path);
    Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

    cvtColor(img, imgGray, COLOR_BGR2GRAY);//灰度

    GaussianBlur(imgGray,imgBlur,Size(3,3), 3, 0);//高斯模糊

    Canny(imgBlur, imgCanny, 50, 150);//边界提取

    Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5));
    dilate(imgCanny, imgDil, kernel);//图像膨胀

    erode(imgDil, imgErode, kernel);//图像侵蚀
    
    imshow("Image", img);
    imshow("Image Gray", imgGray);
    imshow("Image Blur", imgBlur);
    imshow("image Canny", imgCanny);
    imshow("image Dilatation", imgDil);
    imshow("image Erode", imgErode);
    waitKey(0);
    return 0;
}
