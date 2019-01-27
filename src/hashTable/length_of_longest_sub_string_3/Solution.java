/**
 * 给定一个字符串，找出不含有重复字符的最长子串的长度。
 *
 * 示例 1:
 * 输入: "abcabcbb"
 * 输出: 3
 * 解释: 无重复字符的最长子串是 "abc"，其长度为 3。
 *
 * 示例 2:
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 无重复字符的最长子串是 "b"，其长度为 1。
 *
 * 示例 3:
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 无重复字符的最长子串是 "wke"，其长度为 3。
 * 请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。
 **/
package hashTable.length_of_longest_sub_string_3;

import java.util.*;

public class Solution {
    /**
     * 使用的是穷举暴力法
     * */
    public int lengthOfLongestSubstringBF(String s) {
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

    /**
     * 使用java 方法的滑动窗口的方法,使用我的思路肯定是错误的.
     * 需要使用其他的办法,进行处理
     * */
    public int lengthOfLongestSubstringFailed(String s) {
        int left = 0;
        int right = 0;
        List<Character> list = new ArrayList<>();
        HashMap<Character, Integer> hashtable = new HashMap<>();
        int maxLen = 0;
        while (left < s.length()) {
            char tmp = s.charAt(right);
            if (right < s.length() && hashtable.get(tmp) == null) {
                hashtable.put(tmp, hashtable.getOrDefault(tmp, 0) + 1);
                right++;
            } else {
                hashtable.put(tmp, hashtable.get(tmp) - 1);
                left++;

            }
            maxLen = Math.max(maxLen, right - left);
        }
        return maxLen;
    }

    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> hashMap = new HashMap<>();
        int left = 0;
        int right = 0;
        boolean moveLeft = false;
        int maxLen = 0;
        while (right < s.length()) {
            char c = s.charAt(right);
            hashMap.put(c, hashMap.getOrDefault(c, 0) +1);
            if (hashMap.get(c) > 1) {
                // 说明已经有了重复的元素
                // 需要已启动左边了
                moveLeft = true;
            }
            right++;
            while (moveLeft) {
                char charTemp = s.charAt(left);
                if (hashMap.get(charTemp) > 1) {
                    moveLeft = false;
                }
                hashMap.put(charTemp, hashMap.get(charTemp) -1);
                left++;
            }
            maxLen = Math.max(maxLen, right - left);
        }
        return maxLen;
    }

    public static void main(String[] arguments) {
        String str1 = "pwwkew";

        String str2 = "abcabcbb";
        Solution solution = new Solution();
        System.out.println("The length of longest sub string:" + solution.lengthOfLongestSubstring(str2));
    }
}
