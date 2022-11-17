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
int calculate(int n) {
    int sum = 1;
    for (int i = n - 1; i > 0; --i) {
        sum = (sum + 1) * 2;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    int n = 0;
    std::vector<int> value;
    while (1) {
        if (n < 0 || n > 30) {
            break;
        }
        value.push_back(calculate(n));
    }
    for (const auto &v : value) {
        if (v != value.back()) {
            std::cout << v << std::endl;
        } else {
            std::cout << v;
        }
    }
}
