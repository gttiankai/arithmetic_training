/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    int guard = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[guard] != nums[i]) {
        guard++;
        nums[guard] = nums[i];
      }
    }
    return guard + 1;
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  Solution solution;
  int k = solution.removeDuplicates(nums);
  for (int i = 0; i < k; ++i) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
// @lc code=end
