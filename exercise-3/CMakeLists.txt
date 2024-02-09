cmake_minimum_required(VERSION 3.22.1)
project(greeter)
add_executable(main main.cpp)
target_link_libraries(main gtest gtest_main)
