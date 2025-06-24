// Suppose an array of length n sorted in ascending order is rotated between 1
// and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
//
//
//  [4,5,6,7,0,1,2] if it was rotated 4 times.
//  [0,1,2,4,5,6,7] if it was rotated 7 times.
//
//
//  Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results
// in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
//
//  Given the sorted rotated array nums of unique elements, return the minimum
// element of this array.
//
//  You must write an algorithm that runs in O(log n) time.
//
//
//  Example 1:
//
//
// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.
//
//
//  Example 2:
//
//
// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4
// times.
//
//
//  Example 3:
//
//
// Input: nums = [11,13,15,17]
// Output: 11
// Explanation: The original array was [11,13,15,17] and it was rotated 4 times.
//
//
//
//
//  Constraints:
//
//
//  n == nums.length
//  1 <= n <= 5000
//  -5000 <= nums[i] <= 5000
//  All the integers of nums are unique.
//  nums is sorted and rotated between 1 and n times.
//
//
//   Related Topics 数组 二分查找 👍 1256 👎 0

#include <__ostream/basic_ostream.h>

#include <iostream>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    int findMin(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int n = nums.size();
        return BinarySearch(nums, 0, n - 1);
    }

   private:
    int BinarySearch(std::vector<int>& nums, int left, int right) {
        int mid = left + (right - left) / 2;
        if (nums[left] > nums[mid]) {
            // 注意 mid 的边界条件，因为 nums[left] > nums[mid], 所以 mid 有可能
            // 是最小的值，所以又边界是 mid
            return BinarySearch(nums, left, mid);
        }
        if (nums[mid] > nums[right]) {
            // 注意 left 的边界是 mid + 1, 因为 nums[mid] 大与 nums[right],
            // 所以 mid 不可能是最小值
            return BinarySearch(nums, mid + 1, right);
        }
        // nums[left] <= nums[mid] <= nums[right]
        return nums[left];
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> test_case = {
        {3, 1, 2},
        {4, 5, 6, 7, 0, 1, 2, 3},
        {3, 4, 5, 1, 2},
    };
    Solution solution;
    for (auto nums : test_case) {
        std::cout << solution.findMin(nums) << std::endl;
    }
}
