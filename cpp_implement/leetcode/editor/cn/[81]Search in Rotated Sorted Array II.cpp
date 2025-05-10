// There is an integer array nums sorted in non-decreasing order (not
// necessarily with distinct values).
//
//  Before being passed to your function, nums is rotated at an unknown pivot
// index k (0 <= k < nums.length) such that the resulting array is [nums[k],
// nums[k+1] , ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
// For example, [0 ,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and
// become [4,5,6,6,7,0,1, 2,4,4].
//
//  Given the array nums after the rotation and an integer target, return true
// if target is in nums, or false if it is not in nums.
//
//  You must decrease the overall operation steps as much as possible.
//
//
//  Example 1:
//  Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
//
//  Example 2:
//  Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
//
//
//  Constraints:
//
//
//  1 <= nums.length <= 5000
//  -10⁴ <= nums[i] <= 10⁴
//  nums is guaranteed to be rotated at some pivot.
//  -10⁴ <= target <= 10⁴
//
//
//
//  Follow up: This problem is similar to Search in Rotated Sorted Array, but
// nums may contain duplicates. Would this affect the runtime complexity? How
// and why?
//
//
//  Related Topics 数组 二分查找 👍 841 👎 0
#include <iostream>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    bool search(std::vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1) {
            return nums[0] == target;
        }
        int min = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                min = i;
                break;
            }
        }
        if (min == 0) {
            return BinarySearch(nums, target, 0, n - 1);
        }

        int max = min - 1;
        if (target < nums[min] || target > nums[max]) {
            return false;
        } else if (nums[0] <= target && target <= nums[max]) {
            return BinarySearch(nums, target, 0, max);
        } else {
            return BinarySearch(nums, target, min, n - 1);
        }
    }

   private:
    bool BinarySearch(std::vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return false;
        }
        int mid = left + (right - left) / 2;
        if (target == nums[mid]) {
            return true;
        } else if (target > nums[mid]) {
            while (mid < nums.size() - 1 && nums[mid] == nums[mid + 1]) {
                mid++;
            }
            return BinarySearch(nums, target, mid + 1, right);
        } else {
            while (mid - 1 >= 0 && nums[mid - 1] == nums[mid]) {
                mid--;
            }
            return BinarySearch(nums, target, left, mid - 1);
        }
    }
};

// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<int> nums = {2, 2, 2, 3, 2, 2, 2};
    int target            = 3;
    Solution solution;
    std::cout << solution.search(nums, target);
}
