// There is an integer array nums sorted in ascending order (with distinct
// values).
//
//  Prior to being passed to your function, nums is possibly rotated at an
// unknown pivot index k (1 <= k < nums.length) such that the resulting array is
// [nums[k] , nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
//(0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
// and become [4,5,6,7,0 ,1,2].
//
//  Given the array nums after the possible rotation and an integer target,
// return the index of target if it is in nums, or -1 if it is not in nums.
//
//  You must write an algorithm with O(log n) runtime complexity.
//
//
//  Example 1:
//  Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
//  Example 2:
//  Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
//
//  Example 3:
//  Input: nums = [1], target = 0
// Output: -1
//
//
//  Constraints:
//
//
//  1 <= nums.length <= 5000
//  -10⁴ <= nums[i] <= 10⁴
//  All values of nums are unique.
//  nums is an ascending array that is possibly rotated.
//  -10⁴ <= target <= 10⁴
//
//
//  Related Topics 数组 二分查找 👍 3174 👎 0
#include <iostream>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    int search(std::vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        // 1 <= k < nums.length)
        int k = 0;
        while (k < n - 1) {
            if (nums[k] > nums[k + 1]) {
                break;
            }
            k++;
        }
        if (k == n - 1) {
            // 根据 1 <= k < nums.length 的前提条件 k == n-1 这种 case 应该是不会
            // 出现的, 但是题目中给出的 case 却包含这种情况,所以只能通过这个判断
            // 进行特殊 case 的处理
            return BinarySearch(nums, 0, n - 1, target);
        }
        int max = nums[k];
        int min = nums[k + 1];
        if (target < min || target > max) {
            return -1;
        }
        if (target >= nums[0] && target <= nums[k]) {
            return BinarySearch(nums, 0, k, target);
        } else if (target >= nums[k + 1] && target <= nums[n - 1]) {
            return BinarySearch(nums, k + 1, n - 1, target);
        } else {
            return -1;
        }
    }

   private:
    int BinarySearch(std::vector<int>& nums, int left, int right, int target) {
        if (left > right) {
            return -1;
        }
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (target < nums[mid]) {
            return BinarySearch(nums, left, mid - 1, target);

        } else {
            return BinarySearch(nums, mid + 1, right, target);
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::vector<int>> test_case = {{1, 3}};
    std::vector<int> target_num             = {0};
    for (int i = 0; i < test_case.size(); i++) {
        std::cout << solution.search(test_case[i], target_num[i]);
    }
    return 0;
}
