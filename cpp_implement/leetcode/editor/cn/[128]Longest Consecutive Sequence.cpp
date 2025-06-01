// Given an unsorted array of integers nums, return the length of the longest
// consecutive elements sequence.
//
//  You must write an algorithm that runs in O(n) time.
//
//
//  Example 1:
//
//
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
// Therefore its length is 4.
//
//
//  Example 2:
//
//
// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
//
//
//  Example 3:
//
//
// Input: nums = [1,0,1,2]
// Output: 3
//
//
//
//  Constraints:
//
//
//  0 <= nums.length <= 10⁵
//  -10⁹ <= nums[i] <= 10⁹
//
//
//  Related Topics 并查集 数组 哈希表 👍 2513 👎 0

#include <unordered_set>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> set;
        for (auto& num : nums) {
            set.insert(num);
        }
        int longest = 0;
        for (auto& num : set) {
            if (set.find(num - 1) == set.end()) {
                int cur_num  = num;
                int max_size = 1;
                while (set.find(cur_num + 1) != set.end()) {
                    max_size++;
                    cur_num++;
                }
                longest = std::max(longest, max_size);
            }
        }
        return longest;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
