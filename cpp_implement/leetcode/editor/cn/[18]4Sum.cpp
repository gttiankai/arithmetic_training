// Given an array nums of n integers, return an array of all the unique
// quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
//
//
//  0 <= a, b, c, d < n
//  a, b, c, and d are distinct.
//  nums[a] + nums[b] + nums[c] + nums[d] == target
//
//
//  You may return the answer in any order.
//
//
//  Example 1:
//
//
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
//
//
//  Example 2:
//
//
// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
//
//
//
//  Constraints:
//
//
//  1 <= nums.length <= 200
//  -10⁹ <= nums[i] <= 10⁹
//  -10⁹ <= target <= 10⁹
//
//
//  Related Topics 数组 双指针 排序 👍 2050 👎 0
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums,
                                             int target) {
        std::vector<std::vector<int>> ans;
        int n = nums.size();
        if (n < 4) {
            return ans;
        }
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int k = j + 1;
                int m = n - 1;
                while (k < m) {
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[k] + nums[m];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[m]});
                        while (k < m && nums[k] == nums[k + 1]) {
                            // 跳过重复的元素
                            k++;
                        }
                        k++;
                        while (k < m && nums[m] == nums[m - 1]) {
                            // 跳过重复的元素
                            m--;
                        }
                        m--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        m--;
                    }
                }
            }
        }
        return ans;
    }

    std::vector<std::vector<int>> fourSumSlow(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> ans;
        int n = nums.size();
        if (n < 4) {
            return ans;
        }
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int m = n - 1;
                for (int k = j + 1; k < n - 1; k++) {
                    if (k != j + 1 && nums[k] == nums[k - 1]) {
                        continue;
                    }
                    while (k < m) {
                        long long sum =
                            (long long)nums[i] + nums[j] + nums[k] + nums[m];
                        if (sum > target) {
                            m--;
                        } else {
                            break;
                        }
                    }
                    if (k == m) {
                        continue;
                    }
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[k] + nums[m];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[m]});
                    }
                }
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::vector<int>> test_cases;
    test_cases.push_back({1, 0, -1, 0, -2, 2});
    test_cases.push_back({1000000000, 1000000000, 1000000000, 1000000000});
    std::vector<int> target_nums;
    target_nums.push_back({0});
    target_nums.push_back({0});
    for (int i = 0; i < test_cases.size(); ++i) {
        auto ans = solution.fourSum(test_cases[i], target_nums[i]);
    }
}
