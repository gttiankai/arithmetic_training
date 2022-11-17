#include "command_include.h"

/**
 * 时间复杂度：O(log(num))
 * 空间复杂度：O(1)
 * */
class Solution {
 public:
  int numberOfSteps(int num) {
    int count = 0;
    while (num != 0) {
      if (num % 2 == 0) {
        num = num / 2;
      } else {
        num = num -1;
      }
      count++;
    }
    return count;
  }
};
int main(int argc, char* argv[] ) {
  Solution solution;
  std::cout << solution.numberOfSteps(123);
}