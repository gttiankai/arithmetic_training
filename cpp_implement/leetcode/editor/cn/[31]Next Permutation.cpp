// A permutation of an array of integers is an arrangement of its members into a
// sequence or linear order.
//
//
//  For example, for arr = [1,2,3], the following are all the permutations of
// arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
//
//
//  The next permutation of an array of integers is the next lexicographically
// greater permutation of its integer. More formally, if all the permutations of
// the array are sorted in one container according to their lexicographical
// order, then the next permutation of that array is the permutation that
// follows it in the sorted container. If such arrangement is not possible, the
// array must be rearranged as the lowest possible order (i.e., sorted in
// ascending order).
//
//
//  For example, the next permutation of arr = [1,2,3] is [1,3,2].
//  Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
//  While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does
// not have a lexicographical larger rearrangement.
//
//
//  Given an array of integers nums, find the next permutation of nums.
//
//  The replacement must be in place and use only constant extra memory.
//
//
//  Example 1:
//
//
// Input: nums = [1,2,3]
// Output: [1,3,2]
//
//
//  Example 2:
//
//
// Input: nums = [3,2,1]
// Output: [1,2,3]
//
//
//  Example 3:
//
//
// Input: nums = [1,1,5]
// Output: [1,5,1]
//
//
//
//  Constraints:
//
//
//  1 <= nums.length <= 100
//  0 <= nums[i] <= 100
//
//
//  Related Topics 数组 双指针 👍 2678 👎 0
#include <iostream>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * 下面的解法是错误的,没有正确的理解下一个排列的具体含义
     * 下面的解法无法处理: [1, 3, 2]
     **/
    void nextPermutationWrong(std::vector<int>& nums) {
        bool max_permutation = true;
        int i                = nums.size() - 1;
        while (i >= 1) {
            if (nums[i] > nums[i - 1]) {
                max_permutation = false;
                int temp        = nums[i];
                nums[i]         = nums[i - 1];
                nums[i - 1]     = temp;
                break;
            }
            i--;
        }
        if (max_permutation) {
            std::reverse(nums.begin(), nums.end());
        }
    }
    void nextPermutation(std::vector<int>& nums) {}
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::vector<int>> test_case = {
        {1, 2, 3}, {2, 3, 1}, {3, 2, 1}, {1, 3, 2}};
    for (auto case_ : test_case) {
        solution.nextPermutation(case_);
        std::cout << "[ ";
        for (auto c : case_) {
            std::cout << c << ", ";
        }
        std::cout << "]" << std::endl;
    }
}
