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
#include <queue>
/**
 * 两个关键点:
 *  0. 取 x 的每一位的终止条件是什么?
 *  1. 如果 x 大约 INT_MAX 或者小于 INT_MIN 时怎么办?
 * */

class SolutionWrong {
 public:
  /**
   * 目前这种实现方式无法处理小于 INT_MIN 的情况
   * */
  int reverse(int x) {
    bool negative = false;
    if (x < 0) {
      negative = true;
    }
    x = std::abs(x);
    std::queue<int> num_queue;
    /**
     * missing case: 120
     *  case:   120 % 10 equal 0
     *  case:   100
     * */
    while (x != 0) {
      int remain = x % 10;
      x          = x / 10;
      num_queue.push(remain);
    }
    int res = 0;
    while (!num_queue.empty()) {
      if (res > INT_MAX / 10) {
        return 0;
      }
      res = res * 10 + num_queue.front();
      num_queue.pop();
    }
    return negative ? -res : res;
  }
};
class Solution {
 public:
  /**
   * 针对负数,一开始没有想明白,调试之后想清楚了,负数的余数也是负数, res = res* 10 + num 就是负数相加
   *
   * */
  int reverse(int x) {
    int res = 0;
    while (x != 0) {
      int num = x % 10;
      /**
       * -2^31 <= res*10 + num <= 2^31-1
       * 推导出
       * [-2^31/10] <= res < [(2^31 - 1)/10]
       * */
      if (res > INT_MAX / 10 || res < INT_MIN / 10) {
        return 0;
      }
      res = res * 10 + num;
      x   = x / 10;
    }
    return res;
  }
};

int main(int argc, char* argv[]) {
  Solution solution;
  // int x = 1534236469;
  int x = -123;
  std::cout << solution.reverse(x);
  return 0;
}