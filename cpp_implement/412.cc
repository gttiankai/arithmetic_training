/*
Given an integer n, return a string array answer (1-indexed) where:


answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
Example 1:
    Input: n = 3
    Output: ["1","2","Fizz"]
Example 2:
    Input: n = 5
    Output: ["1","2","Fizz","4","Buzz"]
Example 3:
    Input: n = 15
    Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

Constraints: 1 <= n <= 104
 * */
#include <iostream>
#include <string>
#include <vector>
class Solution {
 public:
  std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> res;
    for (int i = 1; i <= n; ++i) {
      std::string answer;
      if (i % 3 == 0) {
        answer += "Fizz";
      }
      if (i % 5 == 0) {
        answer += "Buzz";
      }
      if (answer.empty()) {
        answer += std::to_string(i);
      }
      res.push_back(answer);
    }
    return res;
  }
};
int main(int argc, char* argv[]) {
  Solution solution;
  std::vector<std::string> res = solution.fizzBuzz(17);
  for (const auto& answer : res) {
    std::cout << answer << ", ";
  }
}