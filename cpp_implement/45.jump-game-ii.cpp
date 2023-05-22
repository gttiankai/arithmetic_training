/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] Jump Game II
 */

#include <iostream>
#include <string>
#include <vector>

// @lc code=start
/**
 * 这个题目是基于贪心算法进行实现的
 *
 * */
class Solution {
 public:
  int jump(std::vector<int>& nums) {
    int N       = nums.size();
    int max_pos = 0; // 在遍历过程中,记录能够到达的最远的距离
    int end     = 0; // 在遍历第 i 个元素使,能够达到的最远的距离
    int step    = 0; // 最后返回的要 jump 的步数
    return step;
  }
};

// @lc code=end

class SolutionDP {
 public:
  int jump(std::vector<int>& nums) {
    int N = nums.size();
    std::vector<int> dp(N, -1);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
      int step = nums[i];
      for (int j = i + 1; j <= std::min(i + step, N - 1); ++j) {
        if (dp[j] == -1) {
          dp[j] = 1 + dp[i];
        } else {
          dp[j] = dp[j] < 1 + dp[i] ? dp[j] : 1 + dp[i];
        }
      }
    }
    return dp[N - 1];
  }
};
int main(int argc, char* argv[]) {
  std::vector<int> nums = {2, 3, 1, 1, 4};
  Solution solution;
  std::cout << solution.jump(nums) << std::endl;
  return 0;
}
