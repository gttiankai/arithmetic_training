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
#include <vector>
#include <iostream>

int main() {

    std::vector<int> test(3);
    for (int i = 0; i < 3; ++i) {
        test[i] = i;
    }
    for (int i = 0; i < 4; ++i) {
        test.push_back(i);
    }
    for (const auto& iter: test) {
        std::cout << iter << std::endl;
    }
    return 0;
}


