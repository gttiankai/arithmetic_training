// The k-beauty of an integer num is defined as the number of substrings of num
// when it is read as a string that meet the following conditions:
//
//  It has a length of k.
//  It is a divisor of num.
//
//
//  Given integers num and k, return the k-beauty of num.
//
//  Note:
//
//
//  Leading zeros are allowed.
//  0 is not a divisor of any value.
//
//
//  A substring is a contiguous sequence of characters in a string.
//
//
//  Example 1:
//
//
// Input: num = 240, k = 2
// Output: 2
// Explanation: The following are the substrings of num of length k:
//- "24" from "240": 24 is a divisor of 240.
//- "40" from "240": 40 is a divisor of 240.
// Therefore, the k-beauty is 2.
//
//
//  Example 2:
//
//
// Input: num = 430043, k = 2
// Output: 2
// Explanation: The following are the substrings of num of length k:
//- "43" from "430043": 43 is a divisor of 430043.
//- "30" from "430043": 30 is not a divisor of 430043.
//- "00" from "430043": 0 is not a divisor of 430043.
//- "04" from "430043": 4 is not a divisor of 430043.
//- "43" from "430043": 43 is a divisor of 430043.
// Therefore, the k-beauty is 2.
//
//
//
//  Constraints:
//
//
//  1 <= num <= 10⁹
//  1 <= k <= num.length (taking num as a string)
//
//
//  Related Topics 数学 字符串 滑动窗口 👍 62 👎 0

#include <iostream>
#include <string>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    int divisorSubstrings(int num, int k) {
        int count             = 0;
        std::string num_array = std::to_string(num);
        for (int i = 0; i <= num_array.size() - k; i++) {
            std::string window = num_array.substr(i, k);
            int sub_num        = std::stoi(window);
            if (sub_num == 0) {
                continue;
            }
            if (num % sub_num == 0) {
                count++;
            }
        }
        return count;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char *argv[]) {
    Solution solution;
    int num = 430043;
    int k   = 2;
    std::cout << "the " << num << " has " << k << "-beauty is " << solution.divisorSubstrings(num, k) << std::endl;
    return 0;
}
