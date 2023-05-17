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
 *
 * 1. 使用回溯的方法可以解决这个问题,但是会超时
 *
 *
 * */
class SolutionSlow {
 public:
  int numTrees(int n) {
    return NumBST(1, n);
  }

 private:
  int NumBST(int start, int end) {
    if (start > end) {
      return 1;
    }
    int num = 0;
    for (int i = start; i <= end; ++i) {
      int left  = NumBST(start, i - 1);
      int right = NumBST(i + 1, end);
      num += left * right;
    }
    return num;
  }
};
/**
 * 使用动态规划可以很好的解决这个问题:
 *  dp(n) = dp(0)*dp(n-1-0) + dp(1)*dp(n-1-1) + dp(2)*dp(n-1-2) + ... + dp(n-1)*dp(0)
 *
 * */
class Solution {
 public:
  int numTrees(int n) {
    std::vector<int> dp(n + 1);
    if (n < 2) {
      return n;
    }
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
      dp[i] = NumBST(i, dp);
    }
    return dp[n];
  }
  int NumBST(int n, std::vector<int>& dp) {
    int num = 0;
    for (int i = 0; i < n; ++i) {
      int left_num  = i;
      int right_num = n - i - 1;
      num += dp[left_num] * dp[right_num];
    }
    return num;
  }
};

int main(int argc, char* argv[]) {
  Solution solution;
  int n = 3;
  std::cout << n << " generate BST: " << solution.numTrees(n) << std::endl;
  return 0;
}