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

using std::cout; using std::endl;

struct X {
    X() { cout << "调用构造函数：X()" << endl; }

    X(const X &) { cout << "调用拷贝构造函数：X(const X&)" << endl; }

    ~X() { cout << "调用析构函数：~X()" << endl; }
};

int main(int argc, char **argv) {
    cout << "定义局部变量" << endl;
    X x;
    cout << "定义局部变量完成" << endl;

    std::vector<X> vec;
    cout << "存放在容器" << endl;
    vec.emplace_back(x);
    cout << "程序结束！！！" << endl;
    return 0;
}