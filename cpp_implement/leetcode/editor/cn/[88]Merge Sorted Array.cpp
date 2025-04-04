//You are given two integer arrays nums1 and nums2, sorted in non-decreasing 
//order, and two integers m and n, representing the number of elements in nums1 and 
//nums2 respectively. 
//
// Merge nums1 and nums2 into a single array sorted in non-decreasing order. 
//
// The final sorted array should not be returned by the function, but instead 
//be stored inside the array nums1. To accommodate this, nums1 has a length of m + 
//n, where the first m elements denote the elements that should be merged, and the 
//last n elements are set to 0 and should be ignored. nums2 has a length of n. 
//
// Example 1: 
//Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//Output: [1,2,2,3,5,6]
//Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
//The result of the merge is [1,2,2,3,5,6] with the underlined elements coming 
//from nums1.
//
// Example 2: 
//Input: nums1 = [1], m = 1, nums2 = [], n = 0
//Output: [1]
//Explanation: The arrays we are merging are [1] and [].
//The result of the merge is [1].
//
// Example 3: 
//Input: nums1 = [0], m = 0, nums2 = [1], n = 1
//Output: [1]
//Explanation: The arrays we are merging are [] and [1].
//The result of the merge is [1].
//Note that because m = 0, there are no elements in nums1. The 0 is only there 
//to ensure the merge result can fit in nums1.
// 
// Constraints:
// nums1.length == m + n
// nums2.length == n 
// 0 <= m, n <= 200 
// 1 <= m + n <= 200 
// -10⁹ <= nums1[i], nums2[j] <= 10⁹ 
//
// Follow up: Can you come up with an algorithm that runs in O(m + n) time? 
//
// Related Topics 数组 双指针 排序 
//  👍 2678 👎 0
#include <iostream>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * 时间复杂度: O(m + n)
     * 空间复杂度: O(m + n)
     */
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        // m != 0 and n != 0
        std::vector<int> ans(m + n);
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                ans[i + j] = nums1[i];
                i++;
            } else {
                ans[i + j] = nums2[j];
                j++;
            }
        }
        for (; i < m; ++i) {
            ans[i + j] = nums1[i];
        }
        for (; j < n; ++j) {
            ans[i + j] = nums2[j];
        }
        for (int k = 0; k < m + n; ++k) {
            nums1[k] = ans[k];
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    Solution solution;
    solution.merge(nums1, 3, nums2, 3);
    for (auto& item : nums1) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}