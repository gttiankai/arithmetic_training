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


//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//bool isFlower(int i)
//{
//    int bai = i / 100;
//    int shi = (i / 10) % 10;
//    int ge = i % 10;
//    int he = bai * bai * bai + shi * shi * shi + ge * ge * ge;
//    if (he == i)
//    {
//        return true;
//    }
//    return false;
//}
//
//int main()
//{
//    int co[1000];
//    int i = 0;
//    vector<int> flower;
//    int flowers[4] = {153, 370, 371, 407};
//    /*for (i = 0; i < 100; i++)
//    {
//        co[i] = 0;
//    }
//    for (i = 100; i < 999; i++)
//    {
//        if (isFlower(i))
//        {
//            co[i] = co[i - 1] + 1;
//            flower.push_back(i);
//        }
//        else
//        {
//            co[i] = co[i - 1];
//        }
//    }
//    for (i = 0; i < flower.size(); i++)
//    {
//        cout << flower[i] << endl;
//    }*/
//    vector<int> ret;
//    int a;
//    int b;
//    int idx;
//    while (cin >> b)
//    {
//        idx++;
//        if (idx % 2 == 0)
//        {
//            int count = 0;
//            for (int j = 0; j < 4; j++)
//            {
//                if (a <= flowers[j] && b >= flowers[j])
//                {
//                    count++;
//                    ret.push_back(flowers[j]);
//                }
//            }
//            if (count == 0)
//            {
//                ret.push_back(0);
//            }
//            else
//            {
//                ret.push_back(-1);
//            }
//        }
//        else
//        {
//            a = b;
//        }
//    }
//    int j = 0;
//    for (j = 0; j < ret.size(); j++)
//    {
//        if (ret[j] == 0)
//        {
//            cout << "no" << endl;
//        }
//        else if (ret[j] == -1)
//        {
//            cout << endl;
//        }
//        else
//        {
//            if (j == ret.size() - 1 || ret[j + 1] == -1)
//            {
//                cout << ret[j] << endl;
//                j++;
//            }
//            else
//            {
//                cout << ret[j] << " ";
//            }
//        }
//    }
//    return 0;
//}


#include <iostream>
#include <cmath>
#include <vector>
bool narcissus(int abc) {
    int a = abc / 100;
    int b = (abc -a * 100) /10;
    int c = (abc - a*100 - b*10);
    if ((abc - std::pow(a, 3) - std::pow(b, 3) - std::pow(c ,3)) == 0) {
        return true;
    } else {
        return false;
    }
}
int main(int argc, char* argv[]) {
    int m = 0, n = 0;
    std::vector<std::vector<int>> value;
    while (std::cin >> m >> n) {
        n++;
        std::vector<int> result = {};
        for (int i = m; i < n; ++i) {
            if (narcissus(i)) {
                result.push_back(i);
            }
        }
        value.push_back(result);
    }
    bool first = true;
    for (const auto& item: value) {
        if (!first) {
            std::cout << std::endl;
        }
        if (item.empty()) {
            std::cout << "no" ;
        } else {
            for (const auto& v: item) {
                std::cout << v;
                if ( v != item.back()) {
                    std::cout << " ";
                }
            }
        }
        first = false;
    }
    return 0;
}