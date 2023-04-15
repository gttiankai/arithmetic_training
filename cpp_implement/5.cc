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
/**
 * 有两个需要注意的点:
 *  1. 特殊情况的处理,例如单个字符也是回文子串
 *  2. 这个 Solution 超时了,原因是 i 和 j 遍历太耗时了
 * */
class SolutionSlow {
 public:
  std::string longestPalindrome(std::string s) {
    std::string sub_str;
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = i + 1; j < s.size(); ++j) {
        if (IsPalindrome(s, i, j + 1)) {
          if (count < (j + 1 - i)) {
            count   = j + 1 - i;
            sub_str = s.substr(i, count);
          }
        }
      }
    }
    if (count == 0 && !s.empty()) {
      return s.substr(0, 1);
    }
    return sub_str;
  }

 private:
  /*
   * sub_str: s[start, end)
   * */
  bool IsPalindrome(std::string& s, int start, int end) {
    int size            = end - start;
    std::string sub_str = s.substr(start, size);
    int half            = size / 2;
    for (int i = 0; i < half; ++i) {
      if (sub_str[i] != sub_str[size - 1 - i]) {
        return false;
      }
    }
    return true;
  }
};
/**
 * 动态规划:
 *
 * */
class Solution {
 public:
  std::string longestPalindrome(std::string s) {}
};


int main(int argc, char* argv[]) {
  Solution solution;
  // std::string message = "babad";
  std::string message = "abcd";
  std::cout << solution.longestPalindrome(message) << std::endl;
}