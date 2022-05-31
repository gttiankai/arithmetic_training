// Tencent is pleased to support the open source community by making TNN available.
//
// Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the cmake"License"); you may not use this file except
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
#include <iomanip>

int main(int argc, char* argv[]) {
    int n = 0;
    std::vector<float> value;
    while (std::cin >> n) {
        int max = 0;
        int min = 100;
        int score = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> score;
            sum += score;
            if (score < min) {
                min = score;
            }
            if (score > max) {
                max = score;
            }
        }
        value.push_back(((float)(sum - max - min)) / (float)(n -2));
    }
    for (const auto& v: value) {
        if (v !=  value.back()) {
            std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2) << v <<std::endl;
        } else {
            std::cout <<  std::fixed <<std::setprecision(2) << v;
        }
    }
}