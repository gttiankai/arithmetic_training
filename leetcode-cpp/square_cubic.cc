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
#include <cmath>

int main(int argc, char* argv[]) {
    int begin = 0;
    int end = 0;
    int y = 0;
    int x = 0;
    while (std::cin >> begin >> end) {
        end++;
        for (int i = begin; i < end; ++i) {
            if (i % 2 != 0) {
                y += std::pow(i, 3);
            } else {
                x += std::pow(i, 2);
            }
        }
        std::cout << x << " " << y << std::endl;
        x = y = 0;
    }
}