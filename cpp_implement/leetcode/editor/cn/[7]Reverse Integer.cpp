// Given a signed 32-bit integer x, return x with its digits reversed. If
// reversing x causes the value to go outside the signed 32-bit integer range [-2³¹, 2³¹ - 1], then return 0.
//
//  Assume the environment does not allow you to store 64-bit integers (signed
// or unsigned).
//
//
//  Example 1:
//
// Input: x = 123
// Output: 321
//
//  Example 2:
//
// Input: x = -123
// Output: -321
//
//  Example 3:
//
//
// Input: x = 120
// Output: 21
//
//
//  Constraints:
//
//  -2³¹ <= x <= 2³¹ - 1
//
//
//  Related Topics 数学 👍 4067 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
#include <climits>
#include <iostream>
class Solution {
   public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            // 判断是否溢出的位置是容易犯错的地方,要放在 ans 累加的前面
            // 假设放在累加的后面,会造成 [INT_MIN, INT_MIN/10] 和 [INT_MAX/10, INT_MAX] 这两个值域范围内的整数无法转换
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return 0;
            }
            int reminder = x % 10;
            x            = x / 10;
            ans          = ans * 10 + reminder;
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char *argv[]) {
    Solution solution;
    std::vector<int> test_case = {-2147483412};
    for (auto n : test_case) {
        std::cout << n << " reverse number: " << solution.reverse(n) << std::endl;
    }
    return 0;
}
