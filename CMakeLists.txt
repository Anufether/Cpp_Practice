cmake_minimum_required(VERSION 3.27)
project(CPP_PRACTICE CXX) # 使用CXX指定C++编译器

set(CMAKE_CXX_STANDARD 11) # 使用CXX_STANDARD指定C++标准

# 添加可执行文件并链接function_basic.cc文件
add_executable(function_basic function/function_basic.cc)