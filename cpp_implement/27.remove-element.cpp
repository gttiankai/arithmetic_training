/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] Remove Element
 *
 * https://leetcode.cn/problems/remove-element/description/
 *
 * algorithms
 * Easy (60.22%)
 * Likes:    2417
 * Dislikes: 0
 * Total Accepted:    1.8M
 * Total Submissions: 3M
 * Testcase Example:  '[3,2,2,3]\n3'
 *
 * Given an integer array nums and an integer val, remove all occurrences of
 * val in nums in-place. The order of the elements may be changed. Then return
 * the number of elements in nums which are not equal to val.
 * 
 * Consider the number of elements in nums which are not equal to val be k, to
 * get accepted, you need to do the following things:
 * 
 * 
 * Change the array nums such that the first k elements of nums contain the
 * elements which are not equal to val. The remaining elements of nums are not
 * important as well as the size of nums.
 * Return k.
 * 
 * 
 * Custom Judge:
 * 
 * The judge will test your solution with the following code:
 * 
 * 
 * int[] nums = [...]; // Input array
 * int val = ...; // Value to remove
 * int[] expectedNums = [...]; // The expected answer with correct length.
 *                            // It is sorted with no values equaling val.
 * 
 * int k = removeElement(nums, val); // Calls your implementation
 * 
 * assert k == expectedNums.length;
 * sort(nums, 0, k); // Sort the first k elements of nums
 * for (int i = 0; i < actualLength; i++) {
 *    assert nums[i] == expectedNums[i];
 * }
 * 
 * 
 * If all assertions pass, then your solution will be accepted.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,2,2,3], val = 3
 * Output: 2, nums = [2,2,_,_]
 * Explanation: Your function should return k = 2, with the first two elements
 * of nums being 2.
 * It does not matter what you leave beyond the returned k (hence they are
 * underscores).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,2,2,3,0,4,2], val = 2
 * Output: 5, nums = [0,1,4,0,3,_,_,_]
 * Explanation: Your function should return k = 5, with the first five elements
 * of nums containing 0, 0, 1, 3, and 4.
 * Note that the five elements can be returned in any order.
 * It does not matter what you leave beyond the returned k (hence they are
 * underscores).
 *
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 100
 * 0 <= nums[i] <= 50
 * 0 <= val <= 100
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <algorithm>
class SolutionSlow {
   public:
    int removeElement(std::vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) {
                nums[i] = 101;
            } else {
                k++;
            }
        }
        std::sort(nums.begin(), nums.end());
        return k ;
    }
};
// @lc code=start
class Solution {
   public:
    int removeElement(std::vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        // 这个 guard 用的特别好
        int guard = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                guard++;
                nums[guard] = nums[i];
            }
        }
        return guard + 1;
    }
};
// @lc code=end

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::vector<int>> cases = {
        {3, 2, 2, 3},
        {0, 1, 2, 2, 3, 0, 4, 2},
    };
    std::vector<int> values = {3, 2};
    for (int i = 0; i < cases.size(); ++i) {
        int k = solution.removeElement(cases[i], values[i]);
        std::cout << k << " ";
        for (int j = 0; j < k; ++j) {
            std::cout << cases[i][j] << " ";
        }
        std::cout << std::endl;
    }
}