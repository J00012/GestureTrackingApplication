cmake_minimum_required(VERSION 3.10)
project(GestureTrackingProject)

set(OpenCV_DIR C:/Users/mrpri/Desktop/OpenCV_source/opencv/build)
find_package(OpenCV REQUIRED)

# Added these 2 lines to make sure our compiler uses C++17 or later
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_VERSION})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
