#include <iostream>
#include <ostream>
#include <string>
#include <vector>
/**
   时间复杂度: m 为 strs 中字符串的个数, n 为单个字符串的长度
   时间复杂度为: O(m*n)
   空间复杂度:  O(1)
 */
class Solution {
 public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string ans;
    if (strs.empty()) {
      return ans;
    }
    if (strs.size() == 1) {
      return strs[0];
    }
    ans = strs[0];
    for (int i = 1; i < strs.size(); i++) {
      ans = longestCommonPrefix(ans, strs[i]);
      if (ans.empty()) {
        break;
      }
    }
    return ans;
  }

 private:
  std::string longestCommonPrefix(const std::string& s1, const std::string s2) {
    int i = 0;
    int N = std::min(s1.length(), s2.length());
    while (i < N && s1[i] == s2[i]) {
      i++;
    }
    return s1.substr(0, i);
  }
};

int main(int argc, char* argv[]) {
  std::vector<std::string> strs;
  strs.push_back({"flower"});
  strs.push_back({"flow"});
  strs.push_back({"flight"});

  Solution solution;
  std::cout << solution.longestCommonPrefix(strs) << std::endl;

  return 0;
}
