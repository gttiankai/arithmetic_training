cmake_minimum_required(VERSION 3.15)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 11)

file (GLOB files *.cc)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()