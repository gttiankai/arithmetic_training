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
/*7-5 QPC-排队
n个人排队接水，第i个人接水需要T
​i
​​ 秒，水龙头却 只有一个 。

不过考虑到时间问题，可能只会许可这n个人中的 前面若干人 接水。

对于所有取得许可的人，请安排他们的排队顺序，使得每个人的等待时间之和最小。

输入格式:
第一行为一个正整数n。(1≤n≤10
​5
​​ )

第二行有n个正整数，表示T
​i
​​ 。(1≤T
​i
​​ ≤10000)

输出格式:
n行，每行一个正整数。

第i行的数为许可前i个人接水，得到的最小等待时间和。(答案不会超过2
​63
​​ −1)

样例输入:
3
3 2 1
样例输出:
0
2
4
样例解释:
若只许可一个人接水，没有人等待。

若许可前两个人接水，则让2号先接只需总等待2秒，

若许可前三个人接水，排队顺序为 3, 2, 1：

1号等待1+2=3秒
2号等待1秒
3号等待0秒
总等待时间为4秒
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> ret;
    // 这个是桶的个数
    int numberSum[10001];    // 前i个数有多少个
    long long totSum[10001]; // 前i个数有多少总时间
    for (int i = 0; i < 10001; i++)
    {
        numberSum[i] = 0;
        totSum[i] = 0;
    }
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        sum += temp * (numberSum[10000] - numberSum[temp]); //位于temp之后的人增加的时间
        sum += totSum[temp];                                // 当前此人增加的时间
        for (int j = temp; j < 10001; j++)
        {
            numberSum[j] += 1;
            totSum[j] += temp;
        }
        ret.push_back(sum);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ret[i] << endl;
    }
    return 0;
}