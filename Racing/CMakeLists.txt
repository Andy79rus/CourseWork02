cmake_minimum_required (VERSION 3.20)
set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

project ("Racing")

file(GLOB SOURCES
    *.h
    *.cpp
)

add_library(Racing SHARED ${SOURCES})
target_include_directories(Racing PUBLIC ../Racing)