# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.20)
set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project ("CourseWork02")

add_executable(CourseWork02 CourseWork02.cpp)
add_subdirectory(Racing)
target_link_libraries(CourseWork02 Racing)