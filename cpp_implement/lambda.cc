#include <iostream>
#include <vector>

bool cmp(int a, int b) {
  return a < b;
}

int main(int argc, char* argv[]) {
  std::vector<int> array = {3, 2, 5, 7, 3, 2};
  auto array_bp(array);

  std::sort(array.begin(), array.end(), cmp);
  for (const auto& iter : array) {
    std::cout << iter << " ";
  }
  std::cout << std::endl;

  std::sort(array_bp.begin(), array_bp.end(), [](int a, int b) { return a > b; });
  for (const auto& iter : array_bp) {
    std::cout << iter << " ";
  }
  std::cout << std::endl;
}