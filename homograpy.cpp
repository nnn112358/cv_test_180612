// g++ homograpy.cpp -I/usr/include/opencv2 -I/usr/include/opencv -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_calib3d -lopencv_imgproc


#include <iostream>
#include <opencv2/opencv.hpp>



#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

double stof(std::string str){
double ret;
std::stringstream ss;
ss << str;
ss >> ret;
return ret;
}

vector<string> split(string& input, char delimiter)
{
    istringstream stream(input);
    string field;
    vector<string> result;
    while (getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}

int main(){
    ifstream ifs("data.csv");

	double xin[4];
	double yin[4];
	
	double xout[4];
	double yout[4];

    string line;
    while (getline(ifs, line)) {
        vector<string> strvec = split(line, ',');
        int j=0;
        for (int i=0; i<4;i++){
           
            xin[j]=stof(strvec.at(2*i));
            yin[j]=stof(strvec.at(2*i+1));
           
           cout<<xin[j]<<","<<yin[j]<<"\t";
            j++;
        }
          printf("\n");
    }
    vector<cv::Point2f> match_point1;
    vector<cv::Point2f> match_point2;
  cv::Point2f pts1[] = {cv::Point2f(150,150),cv::Point2f(150,300),cv::Point2f(350,300),cv::Point2f(350,150)};
  cv::Point2f pts2[] = {cv::Point2f(150,150),cv::Point2f(150,400),cv::Point2f(350,300),cv::Point2f(350,150)};

         std::vector<cv::Point2f> obj, scene;
        for (int i = 0; i < 4; i++) {
            obj.push_back(pts1[i]);
            scene.push_back(pts2[i]);
        }
        
        
    cv::Mat H = cv::findHomography(obj, scene,0);
    cout<<H<<endl;

    cv::Mat H2 = cv::getPerspectiveTransform(obj, scene);
    cout<<H2<<endl;
    
    
} 


