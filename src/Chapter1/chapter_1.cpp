#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;
/////////////////// image ////////////////////
// int main(){
//     string path = "/home/zjt/Desktop/opencv_learning/Resources/test.png";
//     Mat img = imread(path);
//     imshow("Image", img);
//     waitKey(0);
//     return 0;
// }



////////////////// video ////////////////////

// int main(){
//     string path = "/home/zjt/Desktop/opencv_learning/Resources/test_video.mp4";
//     VideoCapture cap(path);
//     Mat img;
//     while(true){
//         cap.read(img);

//         imshow("Image", img);
//         waitKey(10);
        
//     }
//     return 0;
// }

///////////////// Webcam ///////////////////////

int main(){
    VideoCapture cap(0);
    Mat img;
    while(true){
        cap.read(img);

        imshow("Image", img);
        waitKey(1);
    }
    return 0;
}