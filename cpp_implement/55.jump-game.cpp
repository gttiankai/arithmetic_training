/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.cn/problems/jump-game/description/
 *
 * algorithms
 * Medium (43.58%)
 * Likes:    2332
 * Dislikes: 0
 * Total Accepted:    713.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * You are given an integer array nums. You are initially positioned at the
 * array's first index, and each element in the array represents your maximum
 * jump length at that position.
 *
 * Return true if you can reach the last index, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 * jump length is 0, which makes it impossible to reach the last index.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^5
 *
 *
 */
#include <cmath>
#include <iostream>
#include <vector>

/**
 * 时间复杂度： 这个时间复杂度不好评估,两个 for 循环的调用，还是很耗时的
 * 空间复杂度： O(N)
 * */
class SolutionSlow {
 public:
  bool canJump(std::vector<int>& nums) {
    int N = nums.size();
    std::vector<bool> jump(N, false);
    jump[0] = true;
    for (int i = 0; i < N; ++i) {
      if (jump[i] == true) {
        for (int j = 1; j <= nums[i] && i + j < N; ++j) {
          jump[i + j] = true;
        }
        if (jump[N - 1]) {
          return true;
        }
      }
    }
    return jump[N - 1];
  }
};
// @lc code=start
class Solution {
 public:
  bool canJumpWrong(std::vector<int>& nums) {
    int N = nums.size();
    if (N == 1) {
      return true;
    }
    int right_max_position = 0;
    for (int i = 0; i < N - 1; ++i) {
      right_max_position = std::max(right_max_position, i + nums[i]);
      if (right_max_position >= N - 1) {
        return true;
      }
    }
    return false;
  }
  bool canJump(std::vector<int>& nums) {
    int N = nums.size();
    if (N == 1) {
      return true;
    }
    int right_max_position = 0;
    for (int i = 0; i < N; ++i) {
      // 必须 i <= right_max_position 才能更新 right_max_position
      if (i <= right_max_position) {
        right_max_position = std::max(right_max_position, i + nums[i]);
        if (right_max_position >= N - 1) {
          return true;
        }
      }
    }
    return false;
  }
};
// @lc code=end
int main(int argc, char* argv[]) {
  std::vector<int> nums = {2, 3, 1, 1, 4};

  Solution solution;
  std::vector<std::vector<int>> test_case;
  test_case.push_back(nums);
  // bad case 1
  test_case.push_back({0});
  // bad case 2
  test_case.push_back({0, 2, 3});

  for (auto& item : test_case) {
    std::cout << solution.canJump(item) << std::endl;
  }
  return 0;
}
