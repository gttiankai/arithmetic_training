// Given an array of integers nums sorted in non-decreasing order, find the
// starting and ending position of a given target value.
//
//  If target is not found in the array, return [-1, -1].
//
//  You must write an algorithm with O(log n) runtime complexity.
//
//
//  Example 1:
//  Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
//  Example 2:
//  Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//
//  Example 3:
//  Input: nums = [], target = 0
// Output: [-1,-1]
//
//
//  Constraints:
//
//
//  0 <= nums.length <= 10⁵
//  -10⁹ <= nums[i] <= 10⁹
//  nums is a non-decreasing array.
//  -10⁹ <= target <= 10⁹
//
//
//  Related Topics 数组 二分查找 👍 3000 👎 0
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> ans = {-1, -1};
        if (nums.empty()) return ans;
        int n = nums.size();
        if (target < nums[0] || target > nums[n - 1]) {
            return ans;
        }
        int i = BinarySearch(nums, 0, n - 1, target);
        if (i == -1) {
            return ans;
        }
        int left  = i;
        int right = i;
        while (left > 0 && nums[left - 1] == nums[left]) {
            left--;
        }
        while (right < n - 1 && nums[right] == nums[right + 1]) {
            right++;
        }
        return {left, right};
    }

   private:
    int BinarySearch(std::vector<int>& nums, int left, int right, int target) {
        if (left > right) {
            return -1;
        }
        int mid = left + (right - left) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target < nums[mid]) {
            while (left < mid && nums[mid - 1] == nums[mid]) {
                mid--;
            }
            return BinarySearch(nums, left, mid - 1, target);
        } else {
            // target > nums[mid]
            while (mid < right && nums[mid] == nums[mid + 1]) {
                mid++;
            }
            return BinarySearch(nums, mid + 1, right, target);
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)
