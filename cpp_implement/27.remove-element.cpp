/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  int removeElement(std::vector<int>& nums, int val) {
    if (nums.empty()) {
      return 0;
    }
    int guard = -1;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != val) {
        guard++;
        nums[guard] = nums[i];
      }
    }
    return guard + 1;
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  int val               = 2;
  Solution solution;
  int k = solution.removeElement(nums, val);
  for (int i = 0; i < k; ++i) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
// @lc code=end
