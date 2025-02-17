/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.cn/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (47.58%)
 * Likes:    2441
 * Dislikes: 0
 * Total Accepted:    1.7M
 * Total Submissions: 3.5M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array of distinct integers and a target value, return the
 * index if the target is found. If not, return the index where it would be if
 * it were inserted in order.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [1,3,5,6], target = 5
 * Output: 2
 *
 * Example 2:
 * Input: nums = [1,3,5,6], target = 2
 * Output: 1
 * 
 * 
 * Example 3:
 * Input: nums = [1,3,5,6], target = 7
 * Output: 4
 * 
 * Constraints:
 * 
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums contains distinct values sorted in ascending order.
 * -10^4 <= target <= 10^4
 *
 */

#include <vector>
#include <iostream>

// @lc code=start
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        // 二分查找
        int left  = 0;
        int right = nums.size() -1;
        return BinarySearch(nums, target, left, right);
    }

   private:
    int BinarySearch(std::vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return left;
        }
        int mid = (left + right) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target < nums[mid]) {
            return BinarySearch(nums, target, left, mid - 1);
        } else {
            return BinarySearch(nums, target, mid + 1, right);
        }
    }
};
// @lc code=end

int main(int argc, char* argv[]) {
    std::vector<int> nums = {1, 3, 5, 6};
    int targe             = 4;
    Solution solution;
    std::cout << solution.searchInsert(nums, targe) << std::endl;
    return 0;
}
