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
#include <string>
#include <utility>
#include <vector>
/**
 * 第一次就成功了
 * */
class SolutionMap {
 public:
  std::string intToRoman(int num) {
    Initial();
    int roman_size = integer_roman_.size();
    std::string res;
    auto item = integer_roman_.rbegin();
    while (item != integer_roman_.rend() && num != 0) {
      int rom = item->first;
      while (num >= rom) {
        res += item->second;
        num -= rom;
      }
      item++;
    }
    return res;
  }

 private:
  void Initial() {
    integer_roman_ = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"},
                      {40, "XL"},  {10, "X"},   {9, "IX"},  {5, "V"},    {4, "IV"},  {1, "I"}};
  }
  std::map<int, std::string> integer_roman_;
};

class Solution {
 public:
  std::string intToRoman(int num) {
    std::vector<std::pair<int, std::string>> integer_roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"},
        {40, "XL"},  {10, "X"},   {9, "IX"},  {5, "V"},    {4, "IV"},  {1, "I"}};
    int roman_size = integer_roman.size();
    std::string res;
    for (int i = 0; i < roman_size; ++i) {
      int roman = integer_roman[i].first;
      while (num >= roman) {
        num -= roman;
        res += integer_roman[i].second;
      }
      if (num == 0) {
        break;
      }
    }
    return res;
  }
};

int main(int argc, char* argv[]) {
  int num = 1994;
  Solution solution;
  std::cout << solution.intToRoman(num) << std::endl;

  return 0;
};