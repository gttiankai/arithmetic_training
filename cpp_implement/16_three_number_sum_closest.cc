#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
/**
 *  1. 暴力穷举法,时间复杂度: O(n^3)
 * **/
class SolutionSlow {
 public:
  int threeSumClosest(std::vector<int>& nums, int target) {
    int N    = nums.size();
    int diff = INT_MAX;
    int ans;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        for (int k = j + 1; k < N; ++k) {
          int sum = nums[i] + nums[j] + nums[k];
          if (sum == target) {
            return sum;
          }
          if (diff > std::abs(sum - target)) {
            diff = std::abs(sum - target);
            ans  = sum;
          }
        }
      }
    }
    return ans;
  }
};

class Solution {
 public:
  int threeSumClosest(std::vector<int>& nums, int target) {
    int ans = 0;
    int N   = nums.size();
    // sort nums by ascending order
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
      }
    }

    return ans = 0;
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums = {-1, 2, 1, -4};
  int target            = 1;
  SolutionSlow solution;
  std::cout << solution.threeSumClosest(nums, target) << std::endl;
  return 0;
}
