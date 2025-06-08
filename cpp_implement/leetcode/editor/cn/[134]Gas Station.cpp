// There are n gas stations along a circular route, where the amount of gas at
// the iᵗʰ station is gas[i].
//
//  You have a car with an unlimited gas tank and it costs cost[i] of gas to
// travel from the iᵗʰ station to its next (i + 1)ᵗʰ station. You begin the
// journey with an empty tank at one of the gas stations.
//
//  Given two integer arrays gas and cost, return the starting gas station's
// index if you can travel around the circuit once in the clockwise direction,
// otherwise return -1. If there exists a solution, it is guaranteed to be
// unique.

//
//
//  Example 1:
//
//
// Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
// Output: 3
// Explanation:
// Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 +
// 4
//  = 4
// Travel to station 4. Your tank = 4 - 1 + 5 = 8
// Travel to station 0. Your tank = 8 - 2 + 1 = 7
// Travel to station 1. Your tank = 7 - 3 + 2 = 6
// Travel to station 2. Your tank = 6 - 4 + 3 = 5
// Travel to station 3. The cost is 5. Your gas is just enough to travel back to
// station 3.
// Therefore, return 3 as the starting index.
//
//
//  Example 2:
//
//
// Input: gas = [2,3,4], cost = [3,4,3]
// Output: -1
// Explanation:
// You can't start at station 0 or 1, as there is not enough gas to travel to
// the next station.
// Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 =
// 4
//
// Travel to station 0. Your tank = 4 - 3 + 2 = 3
// Travel to station 1. Your tank = 3 - 3 + 3 = 3
// You cannot travel back to station 2, as it requires 4 unit of gas but you
// only have 3.
// Therefore, you can't travel around the circuit once no matter where you
// start.
//
//
//
//
//  Constraints:
//
//
//  n == gas.length == cost.length
//  1 <= n <= 10⁵
//  0 <= gas[i], cost[i] <= 10⁴
//  The input is generated such that the answer is unique.
//
//
//  Related Topics 贪心 数组 👍 1858 👎 0
#include <iostream>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)

class Solution {
   public:
    // 下面的实现尝试了从每个位置出发是否能够完成循环,所以时间复杂度很高,
    // 测试没有通过,直接超时了
    int canCompleteCircuitTimeLimit(std::vector<int>& gas,
                                    std::vector<int>& cost) {
        int n = gas.size();
        std::vector<int> start_stattions;
        for (int i = 0; i < n; i++) {
            // find max gas gap
            int diff = gas[i] - cost[i];
            if (diff >= 0) {
                start_stattions.push_back(i);
            }
        }
        for (auto& start : start_stattions) {
            if (CompleteTimeLimit(gas, cost, start)) {
                return start;
            }
        }
        return -1;
    }

   private:
    bool CompleteTimeLimit(std::vector<int>& gas, std::vector<int>& cost,
                           int start) {
        int n         = gas.size();
        int carry_gas = gas[start];
        for (int i = 1; i <= n; i++) {
            int need_gas = cost[(start + i - 1) % n];
            if (need_gas > carry_gas) {
                return false;
            }
            carry_gas = carry_gas - need_gas + gas[(start + i) % n];
        }
        return true;
    }

   public:
    /**
     * 时间复杂度: O(n)
     * 空间复杂度: O(1)
     * 关键点:
     *      假设从 i 出发,最远只能到达  j, 那么从 [i,j] 之间的任意一个站点 k 出发,
     *      能够到达的最远距离不会超过 j, 因为从 i 站点出发,到达 k 站点的时,携带的汽
     *      油量肯定是 >=0 的,要不然 从 i 站点不可能到达 k 站点的.所以可以从 0 号站
     *      出发,统计能够到达的最远的站点 j .
     ***/
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n;) {
            int end = Complete(gas, cost, i);
            if (end == n) {
                return i;
            }
            i = i + end + 1;
        }
        return -1;
    }

   private:
    int Complete(std::vector<int>& gas, std::vector<int>& cost, int start) {
        int n         = gas.size();
        int carry_gas = gas[start];
        for (int i = 1; i <= n; i++) {
            int index    = (start + i - 1) % n;
            int need_gas = cost[index];
            if (need_gas > carry_gas) {
                return i - 1;
            }
            carry_gas = carry_gas - need_gas + gas[(start + i) % n];
        }
        return n;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::vector<int>> gas_cases = {
        {2, 2}, {1, 2, 3, 4, 5}, {2, 3, 4}, {5, 8, 2, 8}};
    std::vector<std::vector<int>> cost_cases = {
        {2, 2}, {3, 4, 5, 1, 2}, {3, 4, 3}, {6, 5, 6, 6}};
    // Solution solution;
    for (int i = 0; i < gas_cases.size(); i++) {
        auto& gas  = gas_cases[i];
        auto& cost = cost_cases[i];
        auto start = solution.canCompleteCircuit(gas, cost);
        std::cout << "start from " << start << " gas station" << std::endl;
    }
    return 0;
}
