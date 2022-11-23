#include "command_include.h"

class Solution {
 public:
  // 使用分治法能够解决所有的问题，但是超时了，需要优化算法
  int CountBST(int start, int end) {
    if (start >= end) {
      return 1;
    }
    int num = 0;
    for (int i = start; i <= end; ++i) {
      int left_num  = CountBST(start, i - 1);
      int right_num = CountBST(i + 1, end);
      num += left_num * right_num;
    }
    return num;
  }
  int numTrees(int n) { return CountBST(1, n); }
};

// 自己想出来的动态规划的解法，真是太棒了
class SolutionOptimize {
 public:
  int CountBST(int n, int* mem) {
    int num = 0;
    for (int i = 0; i < n; ++i) {
      num += mem[i] * mem[n - 1 - i];
    }
    return num;
  }
  int numTrees(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int mem[n + 1];
    mem[0] = 1;
    mem[1] = 1;
    mem[2] = 2;
    for (int i = 3; i <=n ; ++i) {
      mem[i] = CountBST(i, mem);
    }
    return mem[n];
  }
};
int main(int argc, char* argv[]) {
  SolutionOptimize solution;
  std::cout << solution.numTrees(19);
}