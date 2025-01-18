

#include "opencv2/opencv.hpp"

#include <iostream>

int main() {
    std::string imagePath = "./hand_image.jpg";

        // Load the image
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cerr << "Error: Unable to load image at path: " << imagePath << std::endl;
        return -1;
    }

    cv::imshow("Display window", image);
    cv::waitKey(0);
    return 0;
}
