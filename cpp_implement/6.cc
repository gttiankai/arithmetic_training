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
 *  超时了,时间复杂度还没有算清楚
 *
 * */
class Solution {
 public:
  std::string convert(std::string s, int numRows) {
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

int main(int argc, char* argv[]) {
  //std::string s = "0123456789abcdef";
  std::string s = "a";
  int num_rows  = 4;
  Solution solution;
  std::cout << solution.convert(s, num_rows) << std::endl;
}
