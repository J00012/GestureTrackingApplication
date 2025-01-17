cmake_minimum_required(VERSION 3.10)
project(GestureTrackingProject)

set(OpenCV_DIR C:/Users/plumm/Desktop/OpenCV_source/opencv/build)
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_VERSION})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
