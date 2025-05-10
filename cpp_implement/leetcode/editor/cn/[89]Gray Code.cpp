//An n-bit gray code sequence is a sequence of 2ⁿ integers where: 
//
// 
// Every integer is in the inclusive range [0, 2ⁿ - 1], 
// The first integer is 0, 
// An integer appears no more than once in the sequence, 
// The binary representation of every pair of adjacent integers differs by 
//exactly one bit, and 
// The binary representation of the first and last integers differs by exactly 
//one bit. 
// 
//
// Given an integer n, return any valid n-bit gray code sequence. 
//
// 
// Example 1: 
//
// 
//Input: n = 2
//Output: [0,1,3,2]
//Explanation:
//The binary representation of [0,1,3,2] is [00,01,11,10].
//- 00 and 01 differ by one bit
//- 01 and 11 differ by one bit
//- 11 and 10 differ by one bit
//- 10 and 00 differ by one bit
//[0,2,3,1] is also a valid gray code sequence, whose binary representation is [
//00,10,11,01].
//- 00 and 10 differ by one bit
//- 10 and 11 differ by one bit
//- 11 and 01 differ by one bit
//- 01 and 00 differ by one bit
// 
//
// Example 2: 
//
// 
//Input: n = 1
//Output: [0,1]
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 16 
// 
//
// Related Topics 位运算 数学 回溯 👍 700 👎 0
#include <vector>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        for (int i = 2; i <= n; i++) {
            Code(ans, i);
        }
        return ans;
    }
private:
    /**
     * 这个题目最重要的就是找到规律, 就能直接解决这个问题
     ***/
    void Code(std::vector<int>& pre_code, int n ) {
        std::vector<int> code = pre_code;
        std::reverse(pre_code.begin(), pre_code.end());
        int offset = 1 << (n-1);
        for (auto num: pre_code) {
            code.push_back(num + offset);
        }
        pre_code = code;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
