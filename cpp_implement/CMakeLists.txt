cmake_minimum_required(VERSION 3.15)
project(arithmetic_training)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer -g -O0")
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 步骤 1：递归收集所有文件
file(GLOB_RECURSE all_files *.cc *.cpp)
# 步骤 2：过滤掉以 "." 开头的文件名
list(FILTER all_files EXCLUDE REGEX "^.*/\\..+\\.(cpp|cc)$")
foreach (file ${all_files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    string(REPLACE " " "_" exe "${exe}")
    string(REPLACE "[" "" exe "${exe}")
    string(REPLACE "]" "." exe "${exe}")
    string(REPLACE "(" "_" exe "${exe}")
    string(REPLACE ")" "_" exe "${exe}")
    string(REPLACE "'" "_" exe "${exe}")
    add_executable(${exe} ${file})
    message(\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()