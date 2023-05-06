// Tencent is pleased to support the open source community by making TNN available.
//
// Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#include <iostream>
#include <string>
#include <vector>
/**
 * 1. 最简单的办法就是使用遍历的办法,将所有的 area 都计算出来,记录其中的最大值,这种办法直接放弃吧,肯定是超时的
 * 2. 动态规划:
 *      s[n]: height 数组中,添加第 n 个数字之后,新的 max area
 *      m(n) = max(m(n-1), s[n])
 *    时间复杂度: O(n!)
 *    这种方案的时间复杂度还是太高了,还需要继续优化
 *    基于 DP 还有更好的方案吗? 如果连动态规划都不行,那就只剩下直接求解了
 * 3. 直接求解
 *      使用双指针法,有个关键的问题就是移动长板,还是移动短板,
 *      s(i, j) = min(h[i], h[j]) * (j - i)
 *      从公式中可推导出到底移动短板还是长板
 * */
class SolutionSlow {
 public:
  int maxArea(std::vector<int>& height) {
    int n = height.size();
    if (n < 2) {
      return 0;
    }
    std::vector<int> dp(n);
    dp[0]   = 0;
    dp[1]   = std::min(height[0], height[1]);
    int max = dp[1];
    for (int i = 2; i < n; ++i) {
      dp[i] = CalculateMaxArea(height, i, dp[i - 1]);
    }
    return dp[n - 1];
  }

 private:
  int CalculateMaxArea(std::vector<int>& height, int i, int pre_max_area) {
    int max_area = pre_max_area;
    for (int j = 0; j < i; ++j) {
      int area = (i - j) * std::min(height[i], height[j]);
      max_area = area > max_area ? area : max_area;
    }
    return max_area;
  }
};

class Solution {
 public:
  int maxArea(std::vector<int>& height) {
    int N = height.size();
    if (N < 2) {
      return 0;
    }
    int left     = 0;
    int right    = N - 1;
    int max_area = 0;
    while (left < right) {
      int area = std::min(height[left], height[right]) * (right - left);
      max_area = area > max_area ? area : max_area;
      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }
    return max_area;
  }
};

int main(int argc, char* argv[]) {
  Solution solution;
  std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  std::cout << solution.maxArea(height) << std::endl;
  return 0;
}