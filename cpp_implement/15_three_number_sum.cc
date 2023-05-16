#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
/**
1. 这个问题最麻烦的地方在于怎么去除重复的元素
   去除重复的元素必须要进行排序,如果不排序的话,不容易进行重复元素的去除
2. 这个题目有个比较好的地方是双指针的用法

 */
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

int main(int argc, char* argv[]) {
  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
  Solution solution;
  auto ans = solution.threeSum(nums);
  for (const auto& item : ans) {
    std::cout << item[0] << " " << item[1] << " " << item[2] << std::endl;
  }
  return 0;
}
