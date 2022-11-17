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
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

int GetInsertIndex(std::vector<int> &times, int new_value, int &n_sum) {
    n_sum = 0;
    for (int i = 0; i < times.size(); ++i) {
        if (new_value < times[i]) {
            return i;
        } else {
            n_sum += times[i];
        }
    }
    return times.size();
}
//int searchInsert(std::vector<int>& nums, int target) {
//    int n = nums.size();
//    int left = 0, right = n - 1, ans = n;
//    while (left <= right) {
//        int mid = ((right - left) >> 1) + left;
//        if (target <= nums[mid]) {
//            ans = mid;
//            right = mid - 1;
//        } else {
//            left = mid + 1;
//        }
//    }
//    return ans;
//}

//void GetSumTime(std::vector<long long> &sum_list, std::vector<int> &sort_times, int new_value) {
//    long long last = sum_list.back();
//    int m = searchInsert(sort_times, new_value);
//    long long sum = last + (sort_times.size() - m) * new_value;
//    if (m == 0) {
//        sum +=
//    }
//    + sum_list[m] + sort_times[m];
//    sort_times.insert(sort_times.begin() + m, new_value);
//    sum_list.push_back(sum);
//}

void GetSumTime(std::vector<long long> &sum_list, std::vector<int> &sort_times, int new_value) {
    long long last = sum_list.back();
    int n_sum = 0;
    int m = GetInsertIndex(sort_times, new_value, n_sum);
    long long sum = last + (sort_times.size() - m) * new_value + n_sum;
    sort_times.insert(sort_times.begin() + m, new_value);
    sum_list.push_back(sum);
}
//void GetSumTime(long long* sum_list, std::vector<int> &sort_times, int new_value, int index) {
//    long long last = sum_list[index -1];
//    int n_sum = 0;
//    int m = GetInsertIndex(sort_times, new_value, n_sum);
//    long long sum = last + (sort_times.size() - m) * new_value + n_sum;
//    sort_times.insert(sort_times.begin() + m, new_value);
//    sum_list[index] = sum;
//}

int main(int argc, char *argv[]) {
    int n = 0;
    std::cin >> n;
    std::vector<long long> sum_list;
    sum_list.push_back(0);
    std::vector<int> sort_times;
    for (int i = 0; i < n; ++i) {
        int time = 0;
        std::cin >> time;
        GetSumTime(sum_list, sort_times, time);
    }
    for (int i = 1; i < n + 1; i++) {
        if (i != n) {
            std::cout << sum_list[i] << std::endl;
        } else {
            std::cout << sum_list[i];
        }
    }
    return 0;
}

//int main(int argc, char *argv[]) {
////    int n = 100000;
////    std::vector<int> times(100000);
////    for (int i = 0; i < n; ++i) {
////        times[i] = std::rand();
////    }
//    std::clock_t start, end;
//    start = std::clock();
//    //    int n = 0;
//    //    std::cin >> n;
//    //    std::vector<int> times;
//    //    for (int i = 0; i < n; ++i) {
//    //        int time = 0;
//    //        std::cin >> time;
//    //        times.push_back(time);
//    //    }
//    //    std::vector<long long > sum_list(100001);
//        int n = 5;
//        std::vector<int> times = {4, 3, 5, 1, 2};
//    std::vector<long long > sum_list;
//    sum_list.push_back(0);
//    std::vector<int> sort_times;
//    for (int i = 0; i < n; ++i) {
//        //`times[i] = 100000 - i;
//        if (i == 0) {
//            sum_list.push_back(0);
//            sort_times.push_back(times[i]);
//        } else {
//            GetSumTime(sum_list, sort_times, times[i]);
//        }
//    }
//    for (int i = 1; i < n + 1; i++) {
//        if (i != n) {
//            std::cout << sum_list[i] << std::endl;
//        } else {
//            std::cout << sum_list[i];
//        }
//    }
//    end = std::clock();
//    std::cout << std::endl
//              << std::fixed << "Runtime : " << (double) (end - start) * 1000 / CLOCKS_PER_SEC << " ms";
//    return 0;
//}