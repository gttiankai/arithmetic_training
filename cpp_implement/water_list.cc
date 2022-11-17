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
#include <list>
#include <iterator>
#include <ctime>
#include <cmath>

void InsertSort(std::list<int>& sort_times, int t)  {
    auto position = sort_times.end();
    auto iter = sort_times.begin();
    for (; iter != sort_times.end(); iter++) {
        if (t < *iter){
            position = iter;
            break;
        }
    }
    if (position == sort_times.end()){
        sort_times.push_back(t);
    } else {
        sort_times.insert(position, t);
    }
}

long long GetSumTime(std::list<int>& times) {
    long long result= 0;
    long long sum = 0;
    auto iter = times.begin();
    for (int i = 0; i < times.size() -1; i++) {
        sum += *iter;
        result += sum;
        iter++;
    }
    return result;
}

int main(int argc, char *argv[]) {

    int n = 5;
    int times[5] = { 4, 3, 5, 1, 2};
//    int n = 4;
//    int times[5] = { 4, 3, 2, 1};
//    int n = 100000;
//    int times[100000];
//    for (int i = 0; i < n; i++) {
//        times[i] =  std::rand();
//    }
    std::clock_t start, end;
    start = std::clock();
//    int n = 0;
//    std::cin >> n;
//    int times[n];
//    for (int i = 0; i < n; ++i) {
//        std::cin >> times[i];
//    }
    std::list<int> sort_times = {times[0]};
    std::vector<long long > result = {0};
    for (int i = 1; i < n; ++i) {
        InsertSort(sort_times, times[i]);
        auto sum_time = GetSumTime(sort_times);
        result.push_back(sum_time);
    }
    for (int i = 0; i < result.size(); i++) {
        if (i != result.size() -1) {
            std::cout << result[i] << std::endl;
        } else {
            std::cout << result[i];
        }
    }
    end = std::clock();
    std::cout << std::endl << std::fixed <<  "Runtime : "<<(double)(end - start)*1000/CLOCKS_PER_SEC << " ms";
    return 0;
}