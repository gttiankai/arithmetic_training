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
//int NotPrimes(int a)
//{
//    if (a < 40)
//    {
//        return 0;
//    }
//    else if (a == 40)
//    {
//        return 1;
//    }
//    else if (a >= 41 && a <= 43)
//    {
//        return 2;
//    }
//    else if (a >= 44 && a <= 48)
//    {
//        return 3;
//    }
//    else if (a >= 49 && a <= 50)
//    {
//        return 4;
//    }
//    return 0;
//}
//int main()
//{
//    /*for (int i = -39; i <= 50; i++)
//    {
//        cout << i << ": " << i * i + i + 41 << endl;
//    }*/
//    vector<string> ret;
//    int a;
//    int b;
//    int idx;
//    while (cin >> b)
//    {
//        idx++;
//        if (idx % 2 == 0)
//        {
//            if (a == 0 && b == 0)
//            {
//                break;
//            }
//            else
//            {
//                if (NotPrimes(b) - NotPrimes(a - 1) > 0)
//                {
//                    ret.push_back("Sorry");
//                }
//                else
//                {
//                    ret.push_back("OK");
//                }
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
//        cout << ret[j] << endl;
//    }
//    return 0;
//}

#include <cmath>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int calculate(int n) {
    return std::pow(n, 2) + n + 41;
}

int isPrime(int n) {
    float n_sqrt;
    if (n == 2 || n == 3) return 1;
    if (n % 6 != 1 && n % 6 != 5) return 0;
    n_sqrt = floor(sqrt((float) n));
    for (int i = 5; i <= n_sqrt; i += 6) {
        if (n % (i) == 0 | n % (i + 2) == 0) return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int x =0 ,y = 0;
    std::vector<bool> prime_number_list;
    while (std::cin >> x >> y) {
        if (x == y && x == 0 ) {
            break;
        }
        y++;
        for (int i = x; i < y; ++i) {
            int prim = isPrime(calculate(i));
            if (prim == 0) {
                prime_number_list.push_back(false);
                break;
            }
        }
        prime_number_list.push_back(true);
    }
    for (int i = 0; i < prime_number_list.size(); ++i) {
        if (prime_number_list[i]) {
            std::cout << "OK";
        } else {
            std::cout << "Sorry";
        }
        if (i != (prime_number_list.size() -1)) {
            std::cout << std::endl;
        }
    }
    return 0;
}
