//
// Created by 田凯 on 2022/7/6.
//
#include <iostream>

int main(int argc, char* argv[]){
  const int BITS        = 8;
  const float THRESHOLD = (float)(1 << (BITS - 1)) - 1.0f;
  std::cout << "THRESHOLD: " << THRESHOLD << std::endl;
}
