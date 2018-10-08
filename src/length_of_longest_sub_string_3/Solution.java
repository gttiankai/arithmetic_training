/**
 * 给定一个字符串，找出不含有重复字符的最长子串的长度。
 * <p>
 * 示例 1:
 * <p>
 * 输入: "abcabcbb"
 * 输出: 3
 * 解释: 无重复字符的最长子串是 "abc"，其长度为 3。
 * 示例 2:
 * <p>
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 无重复字符的最长子串是 "b"，其长度为 1。
 * 示例 3:
 * <p>
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 无重复字符的最长子串是 "wke"，其长度为 3。
 * 请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。
 **/
package length_of_longest_sub_string_3;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) {
            return 0;
        }
        char[] arrayInput = s.toCharArray();
        int longest = 1;
        ArrayList list = new ArrayList();
        for (int i = 0; i < arrayInput.length; i++) {
            list.add(arrayInput[i]);
            for (int j = i + 1; j < arrayInput.length; j++) {
                if (!list.contains(arrayInput[j])) {
                    list.add(arrayInput[j]);
                    if (longest < list.size()) {
                        longest = list.size();
                    }
                } else {
                    break;
                }
            }
            list.clear();
        }
        return longest;
    }

    public static void main(String[] arguments) {
        String str1 = "pwwkew";

        System.out.println("The length of longest sub string:" + Solution.lengthOfLongestSubstring(str1));
    }
}
