/**
Given an integer array nums of length n and an integer target, find three
integers in nums such that the sum is closest to target.

 Return the sum of the three integers.

 You may assume that each input would have exactly one solution.


 Example 1:


Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


 Example 2:


Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).



 Constraints:


 3 <= nums.length <= 500
 -1000 <= nums[i] <= 1000
 -10⁴ <= target <= 10⁴

 Related Topics 数组 双指针 排序 👍 1719 👎 0
*/
#include <algorithm>
#include <iostream>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int closet_num = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 使用了双指针的解法,从 O(n^3) 降低到了 O(n^2)
            int k = n - 1;
            for (int j = i + 1; j < n - 1; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (std::abs(target - sum) <
                        std::abs(target - closet_num)) {
                        closet_num = sum;
                    }
                    if (sum > target) {
                        k--;
                    } else if (sum < target) {
                        j++;
                    } else {
                        // sum == target
                        return target;
                    }
                }
            }
        }

        return closet_num;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::vector<int>> test_cases;
    test_cases.push_back({-1, 2, 1, -4});
    test_cases.push_back({0, 0, 0});
    std::vector<int> target_case;
    target_case.push_back(1);
    target_case.push_back(1);
    for (int i = 0; i < test_cases.size(); i++) {
        std::cout << solution.threeSumClosest(test_cases[i], target_case[i])
                  << std::endl;
    }
    return 0;
}
