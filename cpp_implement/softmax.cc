//
// Created by 田凯 on 2022/10/13.
//
#include <iostream>
#include <limits>
#include <cmath>
#include "half.hpp"
typedef half_float::half fp16_t;

int main(int argc, char* argv[]) {
  float inf = std::numeric_limits<float>::max();
  std::cout << "float max:" << inf << std::endl;
  float res = std::log(inf);
  std::cout << "ln(float inf)=" << res << std::endl;
  std::cout << "1/(float inf)" << 1/(1/inf + 1) << std::endl;

  fp16_t inf_half = std::numeric_limits<fp16_t>::max();
  std::cout << "float16_t max:" << inf_half << std::endl;
  fp16_t res_fp16 = half_float::log(inf_half);
  std::cout << "ln(float16_t inf)=" << res_fp16 << std::endl;
}