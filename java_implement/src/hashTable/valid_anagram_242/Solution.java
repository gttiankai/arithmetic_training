/**
 * Given two strings s and t , write a function to determine if t is an anagram of s.
 *
 * Example 1:
 *
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 *
 * Input: s = "rat", t = "car"
 * Output: false
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your solution to such case?
 *
 * */
package hashTable.valid_anagram_242;

public class Solution {
    /**
     * 下面的方法失败了，没有考虑下面的例子
     *
     * unite test:
     * s: "aacc"
     * t: "ccac"
     *
     * */
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        char[] chars = t.toCharArray();

        for (int i = 0; i < chars.length; i++) {
            if (!s.contains(String.valueOf(chars[i]))){
                return false;
            }
        }
        return true;
    }
}
