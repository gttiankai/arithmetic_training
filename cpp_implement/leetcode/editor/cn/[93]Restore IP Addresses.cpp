// A valid IP address consists of exactly four integers separated by single
// dots.
//  Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
//
//
//  For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but
//  "0.011
//.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
//
//
//  Given a string s containing only digits, return all possible valid IP
// addresses that can be formed by inserting dots into s. You are not allowed to
// reorder or remove any digits in s. You may return the valid IP addresses in
// any order.
//
//
//  Example 1:
//
//
// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]
//
//
//  Example 2:
//
//
// Input: s = "0000"
// Output: ["0.0.0.0"]
//
//
//  Example 3:
//
//
// Input: s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
//
//
//
//  Constraints:
//
//
//  1 <= s.length <= 20
//  s consists of digits only.
//
//
//  Related Topics 字符串 回溯 👍 1511 👎 0
#include <iostream>
#include <string>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<std::string> restoreIpAddressesComplex(std::string s) {
        std::vector<std::string> ans;
        int len = s.length();
        if (len < 4 || len > 12) {
            return ans;
        }
        std::string ip;
        BackTracking(ans, s, ip, 0, 0);
        return ans;
    }

   private:
    void BackTracking(std::vector<std::string>& ans, std::string& s,
                      std::string& ip, int start, int count) {
        if (count == 4) {
            if (ip.length() == s.length() + 4) {
                ans.push_back(ip.substr(0, ip.length() - 1));
            }
            return;
        }
        int len = s.length();
        if (start <= len - 1 && IsValid(s.substr(start, 1))) {
            ip += s.substr(start, 1) + ".";
            BackTracking(ans, s, ip, start + 1, count + 1);
            ip = ip.substr(0, ip.length() - 2);
        }
        if (start <= len - 2 && IsValid(s.substr(start, 2))) {
            ip += s.substr(start, 2) + ".";
            BackTracking(ans, s, ip, start + 2, count + 1);
            ip = ip.substr(0, ip.length() - 3);
        }
        if (start <= len - 3 && IsValid(s.substr(start, 3))) {
            ip += s.substr(start, 3) + ".";
            BackTracking(ans, s, ip, start + 3, count + 1);
            ip = ip.substr(0, ip.length() - 4);
        }
    }
    bool IsValid(std::string s) {
        int len = s.length();
        if (len == 1) {
            return true;
        } else if ((len == 2 || len == 3) && s[0] != '0' &&
                   std::stoi(s) < 256) {
            return true;
        } else {
            return false;
        }
    }

   public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> ans;
        int len = s.length();
        if (len < 4 || len > 12) {
            return ans;
        }
        std::vector<std::string> ip;
        DFS(ans, s, ip, 0);
        return ans;
    }

   private:
    void DFS(std::vector<std::string>& ans, std::string& s,
             std::vector<std::string>& ip, int start) {
        if (ip.size() == 4) {
            if (start == s.length()) {
                std::string ip_address = "";
                for (int i = 0; i < 3; i++) {
                    ip_address += ip[i] + ".";
                }
                ip_address += ip[3];
                ans.push_back(ip_address);
            }
            return;
        }
        int len = s.length();
        if (start <= len - 1 && IsValid(s.substr(start, 1))) {
            ip.push_back(s.substr(start, 1));
            DFS(ans, s, ip, start + 1);
            ip.pop_back();
        }
        if (start <= len - 2 && IsValid(s.substr(start, 2))) {
            ip.push_back(s.substr(start, 2));
            DFS(ans, s, ip, start + 2);
            ip.pop_back();
        }
        if (start <= len - 3 && IsValid(s.substr(start, 3))) {
            ip.push_back(s.substr(start, 3));
            DFS(ans, s, ip, start + 3);
            ip.pop_back();
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::string> test_case = {
        "101023",
        "25525511135",
        "0000",
    };
    for (auto& item : test_case) {
        auto ans = solution.restoreIpAddresses(item);
        std::cout << item << " valid ip:";
        for (auto& ip : ans) {
            std::cout << ip << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}
