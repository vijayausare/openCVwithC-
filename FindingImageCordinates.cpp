#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace std; 
using namespace cv; 

void onMouse(int event, int x, int y, int flags, void*param){
	Mat* img = reinterpret_cast<Mat*>(param); 

	switch (event){
	case EVENT_FLAG_LBUTTON:{
								int pixelValue = static_cast<int>(img->at<uchar>(Point(x, y))); 
								cout << "The Pixel value at ( " << x << "," << y << " )" << pixelValue << endl; 
	}
		break; 
	}
}

int main(){
	Mat img; 
	img = imread("F:/Photogrammetry_project/OPENCVPRJ/OCV/OCV/img/sample_image33.jpg");
	//img.resize(600, 500); 
	if (img.empty()){
		cout << "Empty Image!" << endl; 
	}
	else {
		//cout << img<<" ";
	}
	imshow("PIC", img); 
	cvSetMouseCallback("PIC", onMouse, reinterpret_cast<void*>(&img)); 

	waitKey(0); 

	return 0; 
}
