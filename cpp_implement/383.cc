/**
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。如果可以，返回 true
；否则返回 false。 magazine 中的每个字符只能在 ransomNote 中使用一次。 示例 1： 输入：ransomNote = "a", magazine = "b"
输出：false
示例 2：
输入：ransomNote = "aa", magazine = "ab"
输出：false
示例 3：
输入：ransomNote = "aa", magazine = "aab"
输出：true
示例：4：
ransomNote = "aab", magazine = "baa"
输出：true
提示：
 1 <= ransomNote.length, magazine.length <= 105
ransomNote 和 magazine 由小写英文字母组成
 * */

#include <string>
using namespace std;
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    // magazine 中的每个字符只能在 ransomNote 中使用一次
    if (magazine.size() < ransomNote.size()) {
      return false;
    }
    int magazine_list[26] = {0};
    for (int i = 0; i < magazine.size(); ++i) {
      int index            = magazine[i] - 'a';
      magazine_list[index] = magazine_list[index] + 1;
    }
    for (int i = 0; i < ransomNote.size(); ++i) {
      int index            = ransomNote[i] - 'a';
      magazine_list[index] = magazine_list[index] - 1;
      if (magazine_list[index] < 0) {
        return false;
      }
    }
    return true;
  }
  bool canConstructSimple(string ransomNote, string magazine) {
    // magazine 中的每个字符只能在 ransomNote 中使用一次
    if (magazine.size() < ransomNote.size()) {
      return false;
    }
    int alpha_list[26] = {0};
    for (const auto& item: magazine) {
      alpha_list[item - 'a']++;
    }
    for (const auto& item: ransomNote) {
      alpha_list[item - 'a']--;
      if (alpha_list[item - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};