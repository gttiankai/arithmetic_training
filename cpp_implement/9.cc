#include <iostream>
#include <ostream>
/**
 * 关键点:
 *    1. reverse 大于 INT_MAX 之后如何处理, 这个地方也是忽略的点
 *    2. 这个题目之所以能够比较好的解决,还有赖于之前对整数的处理的几个题目
 * */
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    int original = x;
    int revers   = 0;
    while (x != 0) {
      int digit = x % 10;
      x         = x / 10;
      if (revers > INT_MAX / 10) {
        return false;
      }
      revers = revers * 10 + digit;
    }
    return original == revers;
  }
};

int main(int argc, char *argv[]) {
  Solution solution;
  std::cout << "12321 is Palindrome: " << solution.isPalindrome(12321) << std::endl;
  std::cout << "1232 is Palindrome: " << solution.isPalindrome(1232) << std::endl;
  std::cout << "1234567899 is Palindrome: " << solution.isPalindrome(1234567899) << std::endl;
  return 0;
}
