#include <iostream>
#include <map>
#include <string>
#include <vector>
/**
   时间复杂度: O(n^2)
 */
class SolutionSlow {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> ans;
    int N = nums.size();
    for (int i = 0; i < N; ++i) {
      int remain = target - nums[i];
      int index = GetRemainIndex(nums, remain, i);
      if (index != -1) {
        ans.push_back(i);
        ans.push_back(index);
        break;
      }
    }
    return ans;
  }

 private:
  int GetRemainIndex(std::vector<int>& nums, int remain, int guard) {
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == remain && i != guard) {
        return i;
      }
    }
    return -1;
  }
};

/**
   时间复杂度: 从 348ms 下降到 16ms 
   时间复杂度: O(N)
 */
class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> ans;
    std::map<int, int> nums_map;
    for (int i = 0; i < nums.size(); ++i) {
      nums_map.insert({nums[i], i});
    }
    for (int i = 0; i < nums.size(); ++i) {
      int remain = target - nums[i];
      if (nums_map.find(remain) != nums_map.end()) {
        if (i != nums_map[remain]) {
          ans.push_back(i);
          ans.push_back(nums_map[remain]);
          break;
        }
      }
    }
    return ans;
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums = {3, 2, 4};
  int target = 6;
  Solution solution;
  auto ans = solution.twoSum(nums, target);
  for (const auto& item : ans) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  return 0;
}
