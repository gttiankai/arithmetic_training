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
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>

void InsertSort(std::vector<int>& times, int t)  {
    for (int i = 0; i < times.size(); ++i) {
        if ( t < times[i])  {
            times.insert(times.begin() + i, t);
            return;
        }
    }
    times.push_back(t);
}

long long GetSumTime(std::vector<int>& times) {
    long long result= 0;
    long long sum = 0;
    for (int i = 1; i < times.size(); ++i) {
        sum += times[i - 1];
        result += sum;
    }
    return result;
}

int main(int argc, char *argv[]) {
    int n = 5;
    std::vector<int> times = {4, 3, 5, 1, 2};
//    const int n = 100000;
//    int times[100000];
//    for (int i = 0; i < n; i++) {
//       times[i] =  std::rand();
//    }
    std::clock_t start, end;
    start = std::clock();
//    int n = 0;
//    std::cin >> n;
//    std::vector<int> times;
//    for (int i = 0; i < n; ++i) {
//        int time = 0;
//        std::cin >> time;
//        times.push_back(time);
//    }
    std::vector<long long> result = {0};
    std::vector<int> sort_times = {times[0]};
    for (int i = 1; i < n; ++i) {
        InsertSort(sort_times, times[i]);
        long long  sum_time = GetSumTime(sort_times);
        result.push_back(sum_time);
    }
    for (const auto &v : result) {
        if (v != result.back()) {
            std::cout << v << std::endl;
        } else {
            std::cout << v;
        }
    }
    end = std::clock();
    std::cout << std::endl << std::fixed <<  "Runtime : "<<(double)(end - start)*1000/CLOCKS_PER_SEC << " ms";
    return 0;
}