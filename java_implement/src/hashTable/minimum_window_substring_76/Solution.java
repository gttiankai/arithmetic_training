/**
 *
 * Given a string S and a string T, find the minimum window in S which will contain all the characters
 *
 * in T in complexity O(n).
 *
 * Example:
 *
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * Note:
 *
 * If there is no such window in S that covers all characters in T, return the empty string "".
 * If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
 *
 * */

package hashTable.minimum_window_substring_76;

import java.util.HashMap;
import java.util.Map;

public class Solution {
    public String minWindow(String s, String t) {
        if (s == null|| t == null | s.length() == 0 || t.length() == 0 || t.length() > s.length()) {
            return "";
        }
        Map<Character, Integer> map = new HashMap<>();
        // init the hash map
        for (char c : t.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        // 整个 map 的个数
        int counter = map.size();
        int left = 0;
        int right = 0;
        int head = 0;
        int minLen = Integer.MAX_VALUE;
        while (right < s.length()) {
            char c = s.charAt(right);
            if (map.containsKey(c)) {
                map.put(c, map.get(c)-1);
                if (map.get(c) == 0) {
                    counter--;
                }
            }
            right++;
            while (counter == 0) {
                char tmpChar = s.charAt(left);
                if (map.containsKey(tmpChar)){
                    map.put(tmpChar, map.get(tmpChar) + 1);
                    if (map.get(tmpChar) > 0) {
                        // 已经不包含完整的
                        counter++;
                    }
                }
                if (right - left < minLen) {
                    minLen = right -left;
                    head = left;
                }
                left++;
            }
        }
        if (minLen == Integer.MAX_VALUE) {
            return "";
        }
        // substring 是左闭右开区间
        return s.substring(head, head+minLen);
    }
}
