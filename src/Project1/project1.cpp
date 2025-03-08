#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;
//使用color.cpp 得到颜色值
vector<vector<int>> mycolors = {{22,71,53,255,117,181}};//yellow hmin<<","<<hmax<<","<<smin<<","<<smax<<","<<vmin<<","<<vmax<<endl;
vector<Scalar> mycolorValues{{52,153,255}};
Mat img;
vector<vector<int>> newPoints;


Point getContours(Mat imgDil) {//imgDil是传入的扩张边缘的图像用来查找轮廓，img是要在其上绘制轮廓的图像
	vector<vector<Point>> contours;//轮廓检测到的轮廓。每个轮廓线存储为一个点的向量
	
	vector<Vec4i> hierarchy;//包含关于映像拓扑的信息  typedef Vec<int, 4> Vec4i;具有4个整数值
	
	//在二值图像中查找轮廓。该函数利用该算法从二值图像中提取轮廓
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);//img：要绘制轮廓在什么图片上，contours：要绘制的轮廓，-1定义要绘制的轮廓号（-1表示所有轮廓），Saclar表示轮廓颜色，2表示厚度
	vector<vector<Point>> conPoly(contours.size());//conploy的数量应小于contours 存储角点
	vector<Rect> boundRect(contours.size());
	//过滤器：通过轮廓面积来过滤噪声

    Point myPoint(0, 0);

	for (int i = 0; i < contours.size(); i++) {//遍历检测到的轮廓
		int area = contourArea(contours[i]);
		
		//cout << area << endl;
		
		string objectType;
		if (area > 1000) {//轮廓面积＞1000才绘制
			//计算轮廓周长或凹坑长度。该函数计算了曲线长度和封闭的周长。
			float peri = arcLength(contours[i], true);//计算封闭轮廓周长
			approxPolyDP(contours[i], conPoly[i],0.02*peri,true);//提取角点 以指定的精度近似多边形曲线。第二个参数conPloy[i]存储近似的结果，是输出。
			
			boundRect[i]=boundingRect(conPoly[i]);//计算边界矩形

            myPoint.x = boundRect[i].x + boundRect[i].width/2;
            myPoint.y = boundRect[i].y;

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
            rectangle/*绘制边界矩形*/(img, boundRect[i].tl()/*tl()：topleft矩形左上角坐标*/, boundRect[i].br()/*br()：bottom right矩形右下角坐标*/, Scalar(0, 255, 0), 5);
		}
	}
    return myPoint;
}

vector<vector<int>> findcolor(Mat img){
    Mat imgHSV;
    cvtColor(img, imgHSV, COLOR_BGR2HSV);
    for (int i =0;i<mycolors.size();i++){
        Scalar lower(mycolors[i][0], mycolors[i][2], mycolors[i][4]);
        Scalar upper(mycolors[i][1], mycolors[i][3], mycolors[i][5]);
        Mat mask;
        inRange(imgHSV, lower, upper, mask);
        //imshow(to_string(i),mask);
        Point mypoint = getContours(mask);
        newPoints.push_back({mypoint.x,mypoint.y,i});
    }
   return newPoints;
}

void draw(vector<vector<int>> newPoints, vector<Scalar> mycolorValues){

    for(int i = 0;i<newPoints.size();i++){
        circle(img, Point(newPoints[i][0],newPoints[i][1]), 10, mycolorValues[newPoints[i][2]], FILLED);
    }
}

int main(){
    VideoCapture cap(0);

    while(true){
        cap.read(img);
        newPoints = findcolor(img);
        draw(newPoints,mycolorValues);
        imshow("Image", img);
        waitKey(1);
    }
    return 0;
}