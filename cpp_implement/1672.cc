#include "command_include.h"
class Solution {
 public:

  /**
   * 时间复杂度 O(M*N)
   * 空间复杂度 O(1)
   *
   * **/
  int maximumWealth(std::vector<std::vector<int>>& accounts) {
    int M   = accounts.size();
    int N   = accounts[0].size();
    int max = 0;
    for (int m = 0; m < M; ++m) {
      int sum = 0;
      for (int n = 0; n < N; ++n) {
        sum += accounts[m][n];
      }
      max = sum > max ? sum : max;
    }
    return max;
  }
};