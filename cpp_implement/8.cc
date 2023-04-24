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

class Solution {
 public:
  int myAtoi(std::string s) {
    long res  = 0;
    int start = EatSpace(s);
    bool sign = true;
    GetSign(s, start, sign);
    for (int i = start; i < s.size(); ++i) {
      if (s[i] < '0' || s[i] > '9') {
        return (int)res;
      }
      if (sign) {
        res = res * 10 + (s[i] - '0');
        if (res > INT_MAX) {
          return INT_MAX;
        }
      } else {
        res = res * 10 - (s[i] - '0');
        if (res < INT_MIN) {
          return INT_MIN;
        }
      }
    }
    return (int)res;
  }

 private:
  int EatSpace(std::string& s) {
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != ' ') {
        return i;
      }
    }
    return s.size();
  }
  void GetSign(std::string& s, int& index, bool& sign) {
    if (s[index] == '-') {
      index++;
      sign = false;
    } else if (s[index] == '+') {
      index++;
      sign = true;
    } else {
      sign = true;
    }
    return;
  }
};

int main(int argc, char* argv[]) {
  // std::string s = " -123ab 12";
  //  ERROR case: +-123
  Solution solution;
  std::cout << "myAtoi(2147483648) = " << solution.myAtoi("2147483648 ") << std::endl;
  std::cout << "myAtoi(214748364 a) = " << solution.myAtoi("214748364 a") << std::endl;
  std::cout << "myAtoi(+-123a) = " << solution.myAtoi("+-123a") << std::endl;

  return 0;
}
