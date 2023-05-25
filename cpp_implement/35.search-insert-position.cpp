/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.cn/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (45.02%)
 * Likes:    2026
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.6M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array of distinct integers and a target value, return the
 * index if the target is found. If not, return the index where it would be if
 * it were inserted in order.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,5,6], target = 5
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,3,5,6], target = 2
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,3,5,6], target = 7
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums contains distinct values sorted in ascending order.
 * -10^4 <= target <= 10^4
 *
 *
 */
#include <iostream>
#include <vector>

// @lc code=start
class Solution {
 public:
  int searchInsert(std::vector<int>& nums, int target) {
    // 二分查找
    int N     = nums.size();
    int left  = 0;
    int right = N - 1;
    if (target > nums[N - 1]) {
      return N;
    }
    if (target < nums[0]) {
      return 0;
    }
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      }
    }
    return left;
  }
};
// @lc code=end

int main(int argc, const char** argv) {
  std::vector<int> nums = {1, 3, 5, 6};
  int targe             = 4;
  Solution solution;
  std::cout << solution.searchInsert(nums, targe) << std::endl;
  return 0;
}