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
#include <map>
#include <set>
#include <string>
/**
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
 IV 4
 IX 9
I 可以放在V(5) 和X(10) 的左边，来表示 4 和 9。
 XL  40
 XC  90
X 可以放在L(50) 和C(100) 的左边，来表示 40 和90。
 CD 400
 CM 900
C 可以放在D(500) 和M(1000) 的左边，来表示400 和900。
 *
 * */
/**
 * bad case: IV vs VI
 * bad case: XC vs CX, 这就造成了下面的解法是不对的,
 * 本质上来说, s[i] + s[i + 1] 的值并不是唯一的,很容易引起错误来;
 * */
class SolutionWrong {
 public:
  int romanToInt(std::string s) {
    InitMap();
    int value = 0;
    int N     = s.size();
    for (int i = 0; i < N;) {
      if (i + 1 < N && (s[i] == 'I' || s[i] == 'X' || s[i] == 'C')) {
        int key = s[i] + s[i + 1];
        if (roman_int_map_.count(key) != 0) {
          value += roman_int_map_[key];
          i += 2;
        } else {
          value += roman_int_map_[s[i]];
          i++;
        }
      } else {
        value += roman_int_map_[s[i]];
        i++;
      }
    }
    return value;
  }

 private:
  void InitMap() {
    roman_int_map_.insert(std::make_pair('I', 1));
    roman_int_map_.insert(std::make_pair('V', 5));
    roman_int_map_.insert(std::make_pair('X', 10));
    roman_int_map_.insert(std::make_pair('L', 50));
    roman_int_map_.insert(std::make_pair('C', 100));
    roman_int_map_.insert(std::make_pair('D', 500));
    roman_int_map_.insert(std::make_pair('M', 1000));
    roman_int_map_.insert(std::make_pair('I' + 'V', 4));
    roman_int_map_.insert(std::make_pair('I' + 'X', 9));
    roman_int_map_.insert(std::make_pair('X' + 'L', 40));
    roman_int_map_.insert(std::make_pair('X' + 'C', 90));
    roman_int_map_.insert(std::make_pair('C' + 'D', 400));
    roman_int_map_.insert(std::make_pair('C' + 'M', 900));
  }
  std::map<int, int> roman_int_map_;
};
/**
 * 虽然通过了所有的测试,但是性能太差了,要详细分析下
 * */
class Solution {
 public:
  int romanToInt(std::string s) {
    InitMap();
    const int N = s.size();
    int value   = 0;
    for (int i = 0; i < N; ) {
      if (i + 1 < N) {
        if (Valid(s, i)) {
          value += roman_int_map_[s[i] + s[i + 1]];
          i += 2;
        } else {
          value += roman_int_map_[s[i]];
          i++;
        }
      } else {
        value += roman_int_map_[s[i]];
        i++;
      }
    }
    return value;
  }

 private:
  void InitMap() {
    roman_int_map_.insert(std::make_pair('I', 1));
    roman_int_map_.insert(std::make_pair('V', 5));
    roman_int_map_.insert(std::make_pair('X', 10));
    roman_int_map_.insert(std::make_pair('L', 50));
    roman_int_map_.insert(std::make_pair('C', 100));
    roman_int_map_.insert(std::make_pair('D', 500));
    roman_int_map_.insert(std::make_pair('M', 1000));
    roman_int_map_.insert(std::make_pair('I' + 'V', 4));
    roman_int_map_.insert(std::make_pair('I' + 'X', 9));
    roman_int_map_.insert(std::make_pair('X' + 'L', 40));
    roman_int_map_.insert(std::make_pair('X' + 'C', 90));
    roman_int_map_.insert(std::make_pair('C' + 'D', 400));
    roman_int_map_.insert(std::make_pair('C' + 'M', 900));
  }
  bool Valid(std::string& s, int pos) {
    if (pos + 1 < s.size()) {
      return roman_set_.find(s.substr(pos, 2)) != roman_set_.end();
    } else {
      return false;
    }
  }
  std::map<int, int> roman_int_map_;
  std::set<std::string> roman_set_ = {"IV", "IX", "XL", "XC", "CD", "CM"};
};

int main(int argc, char* argv[]) {
  std::string rom_number = "MCMXCIV";
  Solution solution;
  //  std::cout << rom_number << " : " << solution.romanToInt(rom_number) << std::endl;
  //  std::cout << "XLLIVXXC"
  //            << " : " << solution.romanToInt("XLLIVXXC") << std::endl;
  //  std::cout << "LVIII"
  //            << " : " << solution.romanToInt("LVIII") << std::endl;

  std::cout << "DCXXI"
            << " : " << solution.romanToInt("DCXXI") << std::endl;
  return 0;
}