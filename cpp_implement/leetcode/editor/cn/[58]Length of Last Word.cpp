//Given a string s consisting of words and spaces, return the length of the 
//last word in the string. 
//
// A word is a maximal substring consisting of non-space characters only. 
//
// 
// Example 1: 
//
// 
//Input: s = "Hello World"
//Output: 5
//Explanation: The last word is "World" with length 5.
// 
//
// Example 2: 
//
// 
//Input: s = "   fly me   to   the moon  "
//Output: 4
//Explanation: The last word is "moon" with length 4.
// 
//
// Example 3: 
//
// 
//Input: s = "luffy is still joyboy"
//Output: 6
//Explanation: The last word is "joyboy" with length 6.
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁴ 
// s consists of only English letters and spaces ' '. 
// There will be at least one word in s. 
// 
//
#include <vector>
#include <string>
#include <iostream>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /**
     * 有一个致命的问题,当输入类似于"test", 这种前面没有 ' ' 的问题时,目前的程序处理不了
     * */
    int lengthOfLastWordWrong(std::string s) {
        int n = s.size();
        bool find_end = false;
        int end_position = n-1;
        int start_position = n - 1;
        for (int i = n-1; i >=0 ; --i) {
            if (s[i] != ' ' && !find_end){
                end_position = i;
                start_position = i;
                find_end = true;
            }
            if (find_end && s[i] != ' '){
                start_position = i;
            }

        }
        return end_position - start_position;
    }
    int lengthOfLastWord(std::string s) {
        if (s.size() == 1) {
            return s[0] == ' ' ? 0 : 1;
        }
        bool start_count = false;
        int count = 0;
        for (int i = s.size() - 1; i >= 0 ; --i) {
            if (s[i] != ' ') {
                start_count = true;
            }
            if (start_count) {
                if (s[i] != ' ') {
                    count++;
                } else {
                    break;
                }
            }
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<std::string> test_case;
    test_case.push_back("   fly me  to  the  moon     ");
    test_case.push_back("day");
    test_case.push_back("Hello World");
    test_case.push_back("luffy is still joyboy");
    Solution solution;
    for (auto& item : test_case) {
        std::cout << item << " the length of the last word: " << solution.lengthOfLastWord(item) << std::endl;
    }

    return 0;
}