#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;

// int main(){
//     string path = "/home/zjt/Desktop/opencv_learning/Resources/test.png";
//     Mat img = imread(path);

//     CascadeClassifier faceCascade;
//     faceCascade.load("/home/zjt/Desktop/opencv_learning/Resources/haarcascade_frontalface_default.xml");

//     vector<Rect> face;
//     faceCascade.detectMultiScale(img,face,1.1,10);
//     for (int i =0; i< face.size(); i++){
//         rectangle(img, face[i].tl(), face[i].br(),Scalar(255, 0, 255), 3);
//     }
//     imshow("img",img);
//     waitKey(0);
//     return 0;
// }
int main(){
    VideoCapture cap(0);
    Mat img;
    while(true){
        cap.read(img);
        CascadeClassifier faceCascade;
        faceCascade.load("/home/zjt/Desktop/opencv_learning/Resources/haarcascade_frontalface_default.xml");

        vector<Rect> face;
        faceCascade.detectMultiScale(img,face,1.1,10);
        if(face.size() == 0)
            cout<<"no"<<endl;
        else
            cout<<"success"<<endl;
            
        for (int i =0; i< face.size(); i++){
            rectangle(img, face[i].tl(), face[i].br(),Scalar(255, 0, 255), 3);
        }
        imshow("Image", img);
        waitKey(1);
    }
    return 0;
}