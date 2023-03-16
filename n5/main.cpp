#include <opencv2/core/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <ctime>
using namespace cv;
using namespace std;

int main(int, char**) {
    Mat frame, frameHsv, back;
    string filename;
    cout << "input background image name" << endl;
    cin >> filename;
    back = imread(filename);
    if(back.data == NULL){
        cerr << "unable to open image\n";
        return -1;
    }
    VideoCapture cap;
    int a;
    int deviceID = 0;             // 0 = open default camera
    int apiID = cv::CAP_ANY;      // 0 = autodetect default API
    cap.open(deviceID, apiID);
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }

    cap.read(frame);
    if (frame.empty()) {
        cerr << "ERROR! blank frame grabbed\n";
        return 0;
    }
    resize(back, back, frame.size());
    int counter = 0;
    time_t sum_c = 0, sum_p = 0, sum_s = 0, sum_cycle = 0;

    time_t global_start = clock();
    for (;;) {
        //time_t cycle_s = clock();
        counter++;

        clock_t c_start = clock();
        cap.read(frame);
        clock_t c_end = clock();
        sum_c += difftime(c_end, c_start);

        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        //resize(back, back, frame.size());
        clock_t p_start = clock();
        Mat mask1, mask2, res1, res2, final_output;
        cvtColor(frame, frameHsv, COLOR_BGR2HSV);
        inRange(frameHsv, Scalar(0, 120, 70), Scalar(240, 255, 255), mask1);
        inRange(frameHsv, Scalar(170, 120, 70), Scalar(180, 255, 255), mask2);
        mask1 = mask1+mask2;
        Mat kernel = Mat::ones(3,3, CV_32F);
        morphologyEx(mask1,mask1,cv::MORPH_OPEN,kernel);
        morphologyEx(mask1,mask1,cv::MORPH_DILATE,kernel);
        bitwise_not(mask1,mask2);
        bitwise_and(frame,frame,res1,mask2);
        bitwise_and(back,back,res2,mask1);
        addWeighted(res1,1,res2,1,0,final_output);
        clock_t p_end = clock();
        sum_p += difftime(p_end, p_start);

        clock_t s_start = clock();
        imshow("Live", final_output);
        clock_t s_end = clock();
        sum_s += difftime(s_end, s_start);

        if (waitKey(15) >= 0)
            break;
        //time_t cycle_e = clock();
        //sum_cycle += difftime(cycle_e, cycle_s);
    }
    time_t global_end = clock();
    //cout << "time total: " << difftime(global_end, global_start) << endl;
    //cout << "frames total:" << counter << endl;
    cout << "fps: " << counter/(difftime(global_end, global_start))*1000 << endl;
    cout << "capture: " << sum_c/difftime(global_end, global_start) << endl;
    cout << "permutation: " << sum_p/difftime(global_end, global_start) << endl;
    cout << "show: " << sum_s/difftime(global_end, global_start) << endl;
   //cout << "sum: " << sum_s+sum_p+sum_c << endl;
    //cout << "sum cycle: " << sum_cycle << endl;
    cin >> a;
    return 0;
}
