/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
/**
 * 这种解法超时了
 * 时间复杂度: O( N^2 )
 * 空间复杂度: O( N )
 *  1. bad case: [-2, -1]
 *      考虑之前的 max 是负数的情况
 * dp(i): 代表长度为 i 的数组的最大子序和
 * dp(i) 和 dp(i-1) 暂时不能组成有递进关系的表达式
 * */
class SolutionSlow {
 public:
  int maxSubArray(std::vector<int>& nums) {
    int N = nums.size();
    std::vector<int> dp(N);
    dp[0] = nums[0];
    for (int i = 1; i < N; ++i) {
      int max = dp[i - 1];
      if (nums[i] > 0) {
        int sum = 0;
        int j   = i;
        // 下面的 while 循环能优化吗 ?
        while (j >= 0) {
          sum += nums[j];
          j--;
          max = sum > max ? sum : max;
        }
      } else {
        max = std::max(nums[i], max);
      }
      // nums[i] <= 0 will not influence max sub array
      dp[i] = max;
    }
    return dp[N - 1];
  }
};
/**
 * 关键点: 巧妙的设置了 f(i) 的定义
 * 我们用 f(i) 代表以第 i 个数结尾的「连续子数组的最大和」
 * f(i) = max{ f(i - 1) + nums[i], nums[i] }
 * 时间复杂度: O(N)
 * 空间复杂度: O(N)
 * */
class SolutionSpace {
 public:
  int maxSubArray(std::vector<int>& nums) {
    int N = nums.size();
    std::vector<int> dp(N);
    dp[0] = nums[0];
    for (int i = 1; i < N; ++i) {
      dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
    }
    int max = dp[0];
    for (int i = 1; i < N; ++i) {
      max = max > dp[i] ? max : dp[i];
    }
    return max;
  }
};
// @lc code=start
/**
 * 我们用 f(i) 代表以第 i 个数结尾的「连续子数组的最大和」
 * f(i) = max{ f(i - 1) + nums[i], nums[i] }
 * 空间复杂度优化: O(N) -> O(1)
 * */
class Solution {
 public:
  int maxSubArray(std::vector<int>& nums) {
    int N       = nums.size();
    int pre_max = nums[0];
    int max_sum = nums[0];
    for (int i = 1; i < N; ++i) {
      pre_max = std::max(pre_max + nums[i], nums[i]);
      max_sum = pre_max > max_sum ? pre_max : max_sum;
    }
    return max_sum;
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  // std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  // std::vector<int> nums = {-2, -1};
  std::vector<int> nums = {5, 4, -1, 7, 8};
  Solution solution;
  std::cout << solution.maxSubArray(nums) << std::endl;
  return 0;
}