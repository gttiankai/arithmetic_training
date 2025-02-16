/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (57.61%)
 * Likes:    3728
 * Dislikes: 0
 * Total Accepted:    2.1M
 * Total Submissions: 3.7M
 * Testcase Example:  '[1,1,2]'
 *
 * Given an integer array nums sorted in non-decreasing(非降序) order, remove the
 * duplicates in-place such that each unique element appears only once. The
 * relative order of the elements should be kept the same. Then return the
 * number of unique elements in nums.
 *
 * Consider the number of unique elements of nums to be k, to get accepted, you
 * need to do the following things:
 *
 * Change the array nums such that the first k elements of nums contain the
 * unique elements in the order they were present in nums initially. The
 * remaining elements of nums are not important as well as the size of
 * nums.
 * Return k.
 *
 *
 * Custom Judge:
 *
 * The judge will test your solution with the following code:
 *
 * int[] nums = [...]; // Input array
 * int[] expectedNums = [...]; // The expected answer with correct length
 *
 * int k = removeDuplicates(nums); // Calls your implementation
 *
 * assert k == expectedNums.length;
 * for (int i = 0; i < k; i++) {
 *    assert nums[i] == expectedNums[i];
 * }
 *
 * If all assertions pass, then your solution will be accepted.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,2]
 * Output: 2, nums = [1,2,_]
 * Explanation: Your function should return k = 2, with the first two elements
 * of nums being 1 and 2 respectively.
 * It does not matter what you leave beyond the returned k (hence they are
 * underscores).
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,0,1,1,1,2,2,3,3,4]
 * Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
 * Explanation: Your function should return k = 5, with the first five elements
 * of nums being 0, 1, 2, 3, and 4 respectively.
 * It does not matter what you leave beyond the returned k (hence they are
 * underscores).
 *
 * Constraints:
 *
 * 1 <= nums.length <= 3 * 10^4
 * -100 <= nums[i] <= 100
 * nums is sorted in non-decreasing order.
 */
#include <iostream>
#include <vector>

// @lc code=start
class Solution {
   public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        int count = 0;
        for (int i = 1; i < n; ++i) {
            if(nums[count] != nums[i]) {
                count ++;
                nums[count] = nums[i];
            }
        }
        return count + 1;
    }
};
// @lc code=end

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> cases = {};

    std::vector<int> case_0 = {0};
    cases.push_back(case_0);
    std::vector<int> case_1 = {0, 1};
    cases.push_back(case_1);
    std::vector<int> case_2 = {0, 1, 1};
    cases.push_back(case_2);
    std::vector<int> case_3 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cases.push_back(case_3);
    std::vector<int> case_4 = {0, 1, 2, 3, 4};
    cases.push_back(case_4);
    Solution solution;
    for (auto& item : cases) {
        int k = solution.removeDuplicates(item);
        std::cout << "ans is " << k << " the array is ";
        for (int i = 0; i < k; ++i) {
            std::cout << item[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
