

#include "opencv2/opencv.hpp"
#include <filesystem> // C++17
#include <iostream>

namespace fs = std::filesystem;

int main() {
    std::cout << "Current Working Directory: " << fs::current_path() << std::endl;

    std::string imagePath = "C:\\Users\\mrpri\\Desktop\\GestureTrackingApplication\\images\\hand_image.jpg"; //relative path
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);
    
    if (image.empty()) {
        std::cerr << "**********\nERROR: \nCould not open or find the image!\n**********" << std::endl;
        return -1;
    }
    
    cv::imshow("Display window", image);
    cv::waitKey(0);
    return 0;
}
