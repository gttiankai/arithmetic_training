// You are given a large integer represented as an integer array digits, where
// each digits[i] is the iᵗʰ digit of the integer. The digits are ordered from most
// significant to least significant in left-to-right order. The large integer does
// not contain any leading 0's.
//
//  Increment the large integer by one and return the resulting array of digits.
//
//
//
//  Example 1:
// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].
//
//
//  Example 2:
// Input: digits = [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
// Incrementing by one gives 4321 + 1 = 4322.
// Thus, the result should be [4,3,2,2].
//
//
//  Example 3:
// Input: digits = [9]
// Output: [1,0]
// Explanation: The array represents the integer 9.
// Incrementing by one gives 9 + 1 = 10.
// Thus, the result should be [1,0].
//
//  Constraints:
//
//  1 <= digits.length <= 100
//  0 <= digits[i] <= 9
//  digits does not contain any leading 0's.
//
//
//  Related Topics 数组 数学

#include <vector>
#include <iostream>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    //  目前的解法很朴素,性能比较差
    // 时间复杂度: O(n)
    std::vector<int> plusOneSlow(std::vector<int>& digits) {
        int n   = digits.size() - 1;
        int sum = digits[n] + 1;
        if (sum >= 10) {
            digits[n] = sum-10;
            bool carry = true;
            n--;
            while (n >= 0) {
                if (carry) {
                    sum = digits[n] + 1;
                }
                if (sum >= 10) {
                    digits[n] = sum - 10;
                    carry     = true;
                    n--;
                } else {
                    digits[n] = sum;
                    carry     = false;
                    break;
                }
            }
            if (carry) {
                std::vector<int> ans(digits.size() + 1);
                ans[0] = 1;
                for (int i = 1; i < ans.size(); ++i) {
                    ans[i] = digits[i - 1];
                }
                return ans;

            } else {
                return digits;
            }
        } else {
            digits[n] = sum;
            return digits;
        }
    }
    /**
     *  1. 如果 digits 的末尾没有 9，例如 [1,2,3]，那么我们直接将末尾的数加一，得到 [1,2,4] 并返回；
     *
     *  2. 如果 digits 的末尾有若干个 9，例如 [1,2,3,9,9]，那么我们只需要找出从末尾开始的第一个不为 9
     * 的元素，即将该元素加一，得到 [1,2,4,9,9]。随后将末尾的 9 全部置零，得到 [1,2,4,0,0] 并返回。
     *
     *  3. 如果 digits 的所有元素都是 9，例如 [9,9,9,9,9]，那么答案为 [1,0,0,0,0,0]。我们只需要构造一个长度比 digits 多
     * 1的新数组，将首元素置为 1，其余元素置为 0 即可。
     * */
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size() -1 ;
        if (digits[n] != 9) {
            digits[n]++;
            return digits;
        } else {
            while (n >= 0 && digits[n] == 9) {
                digits[n] = 0;
                n--;
            }
            if (n >= 0) {
                digits[n]++;
                return digits;
            } else {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> test_case = {{9, 9}, {1, 2, 3}, {4, 3, 2, 1}, {9}};
    Solution solution;
    for (auto& item :test_case) {
        auto ans = solution.plusOne(item);
        for (auto&n :ans) {
            std::cout << n;
        }
        std::cout << std::endl;
    }
    return 0;
}