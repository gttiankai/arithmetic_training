
#include <cfloat>
#include <iomanip>
#include <iostream>

int main(int argc, char* argv[]) {
  float min = std::numeric_limits<float>::min();
  std::cout << std::fixed << std::setprecision(6) << min << std::endl;
  std::cout << std::fixed << std::setprecision(6) <<  FLT_MIN << std::endl;
}