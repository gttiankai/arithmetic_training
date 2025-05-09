// Given an integer array nums sorted in non-decreasing order, remove some
// duplicates in-place such that each unique element appears at most twice. The
// relative order of the elements should be kept the same.
//
//  Since it is impossible to change the length of the array in some languages,
// you must instead have the result be placed in the first part of the array
// nums. More formally, if there are k elements after removing the duplicates,
// then the first k elements of nums should hold the final result. It does not
// matter what you leave beyond the first k elements.
//
//  Return k after placing the final result in the first k slots of nums.
//
//  Do not allocate extra space for another array. You must do this by modifying
// the input array in-place with O(1) extra memory.
//
//  Custom Judge:
//  // The judge will test your solution with the following code:
//
//
// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length
//
// int k = removeDuplicates(nums); // Calls your implementation
//
// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
//
//
//  If all assertions pass, then your solution will be accepted.
//
//
//  Example 1:
//
//
// Input: nums = [1,1,1,2,2,3]
// Output: 5, nums = [1,1,2,2,3,_]
// Explanation: Your function should return k = 5, with the first five elements
// of nums being 1, 1, 2, 2 and 3 respectively.
// It does not matter what you leave beyond the returned k (hence they are
// underscores).
//
//
//  Example 2:
//
//
// Input: nums = [0,0,1,1,1,1,2,3,3]
// Output: 7, nums = [0,0,1,1,2,3,3,_,_]
// Explanation: Your function should return k = 7, with the first seven elements
// of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
// It does not matter what you leave beyond the returned k (hence they are
// underscores).
//
//
//
//  Constraints:
//
//
//  1 <= nums.length <= 3 * 10⁴
//  -10⁴ <= nums[i] <= 10⁴
//  nums is sorted in non-decreasing order.
//
//
//  Related Topics 数组 双指针 👍 1262 👎 0
#include <iostream>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    int removeDuplicatesComplex(std::vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0, j = 0; j < n;) {
            while (j < n && nums[i] == nums[j]) {
                j++;
            }
            if (j - i >= 2) {
                nums[k]     = nums[i];
                nums[k + 1] = nums[i];
                k += 2;
            } else {
                nums[k] = nums[i];
                k++;
            }
            i = j;
        }
        return k;
    }
    int removeDuplicates(std::vector<int>& nums) {
        return work(nums, 2);
    }

   private:
    int work(std::vector<int>& nums, int k) {
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (len < 2 || nums[len - k] != nums[i]) {
                nums[len] = nums[i];
                len++;
            }
        }
        return len;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3, 4, 4};
    Solution solution;
    int k = solution.removeDuplicates(nums);
    for (int i = 0; i < k; i++) {
        std::cout << nums[i] << " ";
    }
}
