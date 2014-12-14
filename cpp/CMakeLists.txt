cmake_minimum_required(VERSION 2.8.4)
project(cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14  -lboost_unit_test_framework")
set(CMAKE_BINARY_DIR build)
set(SOURCE_FILES src/lg.cpp src/capi.cc)
add_executable(cpp src/main.cpp  ${SOURCE_FILES})
add_executable(test src/test.cpp ${SOURCE_FILES})

ADD_LIBRARY(stopwords SHARED ${SOURCE_FILES})