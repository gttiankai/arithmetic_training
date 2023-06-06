/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.cn/problems/3sum/description/
 *
 * algorithms
 * Medium (36.98%)
 * Likes:    5986
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.7M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation: 
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not
 * matter.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */
#include <iostream>
#include <vector>

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> ans;
    int N = nums.size();
    // special case
    if (N < 3) {
      return ans;
    }
    // sort nums ascending
    std::sort(nums.begin(), nums.end());
    // special case
    if (nums[0] > 0 || nums[N - 1] < 0) {
      return ans;
    }
    for (int i = 0; i < N; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int target = -nums[i];
      int k      = N - 1;
      for (int j = i + 1; j < N; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        while (j < k && nums[j] + nums[k] > target) {
          k--;
        }
        if (j == k) {
          break;
        }
        if (nums[j] + nums[k] == target) {
          ans.push_back({nums[i], nums[j], nums[k]});
        }
      }
    }

    return ans;
  }
};

// @lc code=end

int main(int argc, char* argv[]) {
  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
  Solution solution;
  auto ans = solution.threeSum(nums);
  for (const auto& item : ans) {
    std::cout << item[0] << " " << item[1] << " " << item[2] << std::endl;
  }
  return 0;
}

