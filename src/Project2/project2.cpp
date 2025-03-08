#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;
/////////////////// image ////////////////////
Mat imgOriginal, imgGray, imgBlur, imgCanny, imgDil, imgThre, imgWarp;
vector<Point> initialPoints,docPoints;
float w = 420, h=596;

Mat preProcessing(Mat img){
    cvtColor(img, imgGray, COLOR_BGR2GRAY);//灰度
	
    GaussianBlur(imgGray,imgBlur,Size(3,3), 3, 0);//高斯模糊

    Canny(imgBlur, imgCanny, 50, 150);//边界提取

    Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5));
    dilate(imgCanny, imgDil, kernel);//图像膨胀

    return imgDil;
}

vector<Point> getContours(Mat imgDil) {
	vector<vector<Point>> contours;
	
	vector<Vec4i> hierarchy;
	

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	

    int maxarea;
    vector<Point> biggest;  


	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);
		
		//cout << area << endl;
		
		string objectType;
		if (area > 1000) {
			
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i],0.02*peri,true);

            if(area > maxarea && conPoly[i].size() == 4){

                drawContours(imgOriginal, conPoly, i, Scalar(255, 0, 255), 5);
                maxarea = area;
                biggest = {conPoly[i][0],conPoly[i][1],conPoly[i][2],conPoly[i][3]};
            }

			
            //rectangle(imgOriginal, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
		}
	}
    return biggest;
}
void drawPoints (vector<Point> points, Scalar color){
    for(int i =0; i< points.size();i++){
        circle(imgOriginal, points[i], 10,color,FILLED);
        putText(imgOriginal, to_string(i), points[i],FONT_HERSHEY_PLAIN,4,color,4);
    }
}

vector<Point> reorder(vector<Point> points){
    vector<Point> newPoints;
    vector<int> sumPoints, subPoints;
    for(int i = 0;i<4;i++){
        sumPoints.push_back(points[i].x + points[i].y);
        subPoints.push_back(points[i].x - points[i].y);
    }
    //得到索引
    newPoints.push_back(points[min_element(sumPoints.begin(),sumPoints.end()) - sumPoints.begin()]);// 0
    newPoints.push_back(points[max_element(subPoints.begin(),subPoints.end()) - subPoints.begin()]);// 1
    newPoints.push_back(points[min_element(subPoints.begin(),subPoints.end()) - subPoints.begin()]);// 2
    newPoints.push_back(points[max_element(sumPoints.begin(),sumPoints.end()) - sumPoints.begin()]);// 3


    return newPoints;
}

Mat getWarp(Mat img, vector<Point> points, float w, float h){

    Point2f src[4] = {points[0], points[1], points[2], points[3]};
    Point2f dst[4] = {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};

    Mat Matrix = getPerspectiveTransform(src ,dst);
    warpPerspective(img, imgWarp, Matrix,Point(w,h));
    return imgWarp;
}
int main(){
    string path = "/home/zjt/Desktop/opencv_learning/Resources/paper.jpg";
    imgOriginal = imread(path);
    resize(imgOriginal, imgOriginal,Size(),0.5,0.5);

    //预处理
    imgThre = preProcessing(imgOriginal);
    //提取轮廓
    initialPoints = getContours(imgThre);
    docPoints = reorder(initialPoints);
    drawPoints(docPoints,Scalar(0,0,255));
    
    //处理 Warp
    imgWarp = getWarp(imgOriginal, docPoints, w, h);

    imshow("Image", imgOriginal);
    imshow("imgThre", imgThre);
    imshow("imgWarp", imgWarp);
    waitKey(0);
    return 0;
}