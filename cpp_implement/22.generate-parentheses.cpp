/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include <iostream>
#include <set>
#include <string>
#include <vector>

/**
 * 回溯法,虽然使用回溯法不是最优的,但是这个方法值得用来是线下
 * */
class SolutionBacktrack {
 public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> ans;
    std::string current;
    Generate(ans, current, 0, 0, n);
    return ans;
  }

 private:
  void Generate(std::vector<std::string>& ans, std::string& cur, int left, int right, int n) {
    if (cur.size() == n * 2) {
      ans.push_back(cur);
    }
    if (left < n) {
      cur.push_back('(');
      Generate(ans, cur, left + 1, right, n);
      cur.pop_back();
    }
    if (right < left) {
      cur.push_back(')');
      Generate(ans, cur, left, right + 1, n);
      cur.pop_back();
    }
  }
};

// @lc code=start

class Solution {
 public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::vector<std::string>> dp(n + 1);
    dp[0] = {""};
    dp[1] = {"()"};
    for (int i = 2; i < n + 1; ++i) {
      for (int k = 0; k < i; ++k) {
        // if i = 2, then k = 0 , 1
        for (const auto p : dp[k]) {
          for (const auto q : dp[i - 1 - k]) {
            std::string parentheses = "(" + p + ")" + q;
            dp[i].push_back(parentheses);
          }
        }
      }
    }
    return dp[n];
  }
};

// @lc code=end

int main(int argc, char* argv[]) {
  int n = 3;
  SolutionBacktrack solution;
  auto ans = solution.generateParenthesis(n);
  for (const auto& item : ans) {
    std::cout << item << std::endl;
  }
  std::cout << std::endl;
  return 0;
}