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
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 * 超时的原因是: 二维数组的创建浪费了大量的时间,
 * 超时的关键云因竟然是: 没有对特殊情况的考虑
 * 但是即使实现了对特殊情况的考虑,我的实现也并不快
 * */
class SolutionSlow {
 public:
  std::string convert(std::string s, int numRows) {
    if (numRows == 1 || s.size() <= numRows) {
      return s;
    }
    std::vector<std::vector<char>> zig_zag(numRows, std::vector<char>());
    bool down  = true;
    int window = 0;
    for (int i = 0; i < s.size();) {
      if (down) {
        if (window < numRows) {
          zig_zag[window].push_back(s[i]);
          window++;
          i++;
        } else {
          down = false;
          window -= 2;
        }
      } else {
        if (window >= 0) {
          zig_zag[window].push_back(s[i]);
          window--;
          i++;
        } else {
          down = true;
          window += 2;
        }
      }
    }
    std::string res;
    for (const auto& item : zig_zag) {
      res += std::string(item.begin(), item.end());
    }
    return res;
  }
};

class SolutionComplex {
 public:
  std::string convert(std::string s, int numRows) {
    /*
     * 下面特殊情况的代码也要考虑进去,如果没有这部分会超时
     * */
    if (numRows == 1 || s.size() <= numRows) {
      return s;
    }
    std::vector<std::string> zig_zag(numRows);
    bool down  = true;
    int window = 0;
    for (int i = 0; i < s.size();) {
      if (down) {
        if (window < numRows) {
          zig_zag[window] += s[i];
          window++;
          i++;
        } else {
          down = false;
          window -= 2;
        }
      } else {
        if (window >= 0) {
          zig_zag[window] += s[i];
          window--;
          i++;
        } else {
          down = true;
          window += 2;
        }
      }
    }
    std::string res;
    for (const auto& item : zig_zag) {
      res += std::string(item.begin(), item.end());
    }
    return res;
  }
};

class Solution {
 public:
  std::string convert(std::string message, int num_row) {
    int size = message.size();
    if (size <= 1 || size <= num_row) {
      return message;
    }
    std::vector<std::string> zig_zag;
    int zig_zag_size = num_row * 2 - 2;
    for (int i = 0, window = 0; i < size; ++i) {
      zig_zag[window] += message[i];
      i % zig_zag_size < num_row - 1 ? window++ : window--;
    }

    std::string res;
    for (const auto& item : zig_zag) {
      res += std::string(item.begin(), item.end());
    }
    return res;
  }
};

int main(int argc, char* argv[]) {
  std::string s = "0123456789abcdef";
  int num_rows  = 4;
  SolutionSlow solution_slow;
  std::cout << solution_slow.convert(s, num_rows) << std::endl;
  Solution solution;
  std::cout << solution.convert(s, num_rows) << std::endl;
}
