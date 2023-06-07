/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.38%)
 * Likes:    2325
 * Dislikes: 0
 * Total Accepted:    798.7K
 * Total Submissions: 1.9M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in non-decreasing order, find the
 * starting and ending position of a given target value.
 *
 * If target is not found in the array, return [-1, -1].
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include "integer_utils.h"

// @lc code=start
/**
 * 解法 1： 二分查找
 *
 *
 * */
class Solution {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    std::vector<int> range(2, -1);
    int N     = nums.size();
    int left  = 0;
    int right = N - 1;
    int mid   = (left + right) / 2;
    while (left <= right) {
      if (nums[mid] == target) {
        break;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
      mid = (left + right) / 2;
    }
    if (left <= right) {
      for (int i = mid; i >= left; --i) {
        if (nums[i] == target) {
          range[0] = i;
        } else {
          break;
        }
      }
      for (int i = mid; i <= right; ++i) {
        if (nums[i] == target) {
          range[1] = i;
        } else {
          break;
        }
      }
    }
    return range;
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  Solution solution;
  std::vector<std::string> test_case;
  std::vector<int> target;
  /**
   * bad case
   * 错误的原因是：for (int i = mid; i <= right; ++i), i 的范围可以等于 right
   * */
  test_case.push_back("[1]");
  target.push_back(1);

  test_case.push_back("[5, 7, 7, 8, 8, 10]");
  target.push_back(8);
  test_case.push_back("[5, 7, 7, 8, 8, 10]");
  target.push_back(6);
  for (int i = 0; i < test_case.size(); ++i) {
    auto item = StringToIntegerVector(test_case[i]);
    auto ans  = solution.searchRange(item, target[i]);
    std::cout << test_case[i] << " search " << target[i] << " : [" << ans[0] << ", " << ans[1] << "]" << std::endl;
  }

  return 0;
}
