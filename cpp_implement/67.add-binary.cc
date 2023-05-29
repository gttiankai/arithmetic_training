//
// Created by Tiankai on 2023/5/27.
//
#include <iostream>
#include <string>

class Solution {
 public:
  std::string addBinary(std::string a, std::string b) {
    int carry       = 0;
    std::string ans = "";
    auto iter_a     = a.rbegin();
    auto iter_b     = b.rbegin();
    while (iter_a != a.rend() && iter_b != b.rend()) {
      int num = (*iter_a - '0') + (*iter_b - '0') + carry;
      if (num > 1) {
        carry = 1;
        ans.insert(ans.begin(), char(num - 2 + '0'));
      } else {
        ans.insert(ans.begin(), char(num + '0'));
        carry = 0;
      }
      iter_a++;
      iter_b++;
    }
    while (iter_a != a.rend()) {
      int num = (*iter_a - '0') + carry;
      if (num > 1) {
        carry = 1;
        ans.insert(ans.begin(), char(num - 2 + '0'));
      } else {
        ans.insert(ans.begin(), char(num + '0'));
        carry = 0;
      }
      iter_a++;
    }
    while (iter_b != b.rend()) {
      int num = (*iter_b - '0') + carry;
      if (num > 1) {
        carry = 1;
        ans.insert(ans.begin(), char(num - 2 + '0'));
      } else {
        ans.insert(ans.begin(), char(num + '0'));
        carry = 0;
      }
      iter_b++;
    }
    if (carry == 1) {
      ans.insert(ans.begin(), '1');
    }
    return ans;
  }
};

int main(int argc, char* argv[]) {
  std::string a = "1111";
  std::string b = "1111";
  Solution solution;
  std::cout << solution.addBinary(a, b) << std::endl;
}