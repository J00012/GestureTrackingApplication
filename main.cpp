

// #include "opencv2/opencv.hpp"
// #include <filesystem> // C++17
// #include <iostream>

// namespace fs = std::filesystem;

// int main() {
//     std::cout << "Current Working Directory: " << fs::current_path() << std::endl;

//     std::string imagePath = "C:\\Users\\mrpri\\Desktop\\GestureTrackingApplication\\images\\hand_image.jpg"; //relative path
//     cv::Mat image = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);
    
//     if (image.empty()) {
//         std::cerr << "**********\nERROR: \nCould not open or find the image!\n**********" << std::endl;
//         return -1;
//     }
    
//     cv::imshow("Display window", image);
//     cv::waitKey(0);
//     return 0;
// }




/******************************************
 * 
 * This is a basic example. 
 * For more advanced gesture recognition, 
 * we can train models or integrate frameworks like Mediapipe for pre-trained hand-tracking models.
 * 
 * Replacing the still image input with a live video feed from a webcam example below.
 * 
 *****************************************/

#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Open webcam; We use "cv:: videocapture" to access the webcam
    cv::VideoCapture cap(0); // 0 is the default camera

    if (!cap.isOpened()) {              // if no webcam is being used at the moment.
        std::cerr << "Error: Unable to access the webcam!" << std::endl;
        return -1;              
    }
    
    /*** Variables (all with the data type called, "cv::Mat"): 
     * frame- stores the raw image captured directly from the webcam. 
     * Traits: the original, full color frame in the BGR color space, openCV uses BGR instead of RGB)
     * size depends on the resolution of the webcam! (ex: 640 x 480 pixels)
     * 
     * grayFrame- grayscale version of the frame. 
     * Traits: converts original 3-channel (color) image into a single channel (grayscale) image for simpler processing.
     * Easier to analyze for pattern detection and REDUCE computational complexity. 
     * obtained using-> cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);
     * ex: a grayscale image matrixx with pixel values ranging from 0(black) to 255(white).
     * 
     * binaryframe- It simplifies image processing further by isolating key features(ex: hand) from the background. 
     * Traits: each pixel is either black(0) or white(255), determined by a threshold
     * A binary (black and white version of the grayFrame). Highlights key features in black and white!!! 
     * created by using --> cv::threshold(grayFrame, binaryFrame, 100, 255, cv::THRESH_BINARY);
     * ex: Here, any pixel in grayFrame with intensity greater than 100 is set to 255(white), and others are set to 0 (black).
     * 
    */
    cv::Mat frame, grayFrame, binaryFrame;


    // Keeps the program running at all times
    while (true) { 

        // Capture frame from webcam
        cap >> frame;
        if (frame.empty()) {
            std::cerr << "Error: Blank frame grabbed!" << std::endl;
            break;
        }

        // Step 1: Preprocess the frame
        cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY); // Convert to grayscale
        cv::GaussianBlur(grayFrame, grayFrame, cv::Size(15, 15), 0); // Reduce noise
        cv::threshold(grayFrame, binaryFrame, 100, 255, cv::THRESH_BINARY); // Binarize


        // Step 2: Find contours (Helpful tip: (GREEN LINES ON LIVE FEED BTW) - curves that join points along an object's boundary that have the same color or intensity. )
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(binaryFrame, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        // IF we have any contours on the camera. 
        if (!contours.empty()) {

            // Step 3: Identify the largest contour (likely the hand)
            double maxArea = 0;
            int largestContourIndex = -1;
            for (size_t i = 0; i < contours.size(); i++) {
                double area = cv::contourArea(contours[i]);
                if (area > maxArea) {
                    maxArea = area;
                    largestContourIndex = i;
                }
            }

            if (largestContourIndex != -1) {
                // Draw the largest contour
                cv::drawContours(frame, contours, largestContourIndex, cv::Scalar(0, 255, 0), 2);

                // Step 4: Find convex hull
                std::vector<cv::Point> hull;
                cv::convexHull(contours[largestContourIndex], hull);

                // Draw the convex hull
                cv::polylines(frame, hull, true, cv::Scalar(255, 0, 0), 2);

                // Step 5: Detect and count fingers using convexity defects
                std::vector<int> hullIndices;
                cv::convexHull(contours[largestContourIndex], hullIndices, false);

                std::vector<cv::Vec4i> defects;
                cv::convexityDefects(contours[largestContourIndex], hullIndices, defects);

                int fingerCount = 0;
                for (const auto& defect : defects) {
                    float depth = defect[3] / 256.0; // Depth of defect point
                    if (depth > 20) { // Threshold for finger detection
                        fingerCount++;
                    }
                }

                // Display the finger count
                std::string gestureText = "Fingers: " + std::to_string(fingerCount);
                cv::putText(frame, gestureText, cv::Point(50, 50), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 255), 2);
            }
        }

        // If we don't find contours (Ex: finger or tape blocking web cam)
        // Then no contours will be detected or any ui showing finger count will pop up on the camera!

        // Step 6: Display the frame
        cv::imshow("Hand Gesture Detection", frame); // imshow() methtod is used to display an image in a window. 


        // Check if the window is closed (If I want to push the x on the )
        if (cv::getWindowProperty("Hand Gesture Detection", cv::WND_PROP_VISIBLE) < 1) {
            std::cout << "Window closed by user." << std::endl;
            break;
        }

        // Exit on pressing 'ESC'
        if (cv::waitKey(10) == 27) {
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
