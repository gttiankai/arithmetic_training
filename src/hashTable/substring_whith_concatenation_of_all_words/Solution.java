/**
 * You are given a string, s, and a list of words, words, that are all of the same
 *
 * length. Find all starting indices of substring(s) in s that is a concatenation
 *
 * of each word in words exactly once and without any intervening characters.
 *
 * Example 1:
 *
 * Input:
 *   s = "barfoothefoobarman",
 *   words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar"
 * respectively.
 *
 * The output order does not matter, returning [9,0] is fine too.
 * Example 2:
 *
 * Input:
 *   s = "wordgoodgoodgoodbestword",
 *   words = ["word","good","best","word"]
 * Output: []
 *
 * */

package hashTable.substring_whith_concatenation_of_all_words;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        if (s == null || words == null || words[0].length() > s.length()) {
            return res;
        }
        int left = 0;
        int right = 0;
        int length = words[0].length();
        Map<String, Integer> map = new HashMap<String, Integer>();
        for (String word: words) {
            map.put(word, map.getOrDefault(word, 0) +1);
        }
        int counter = map.size();
        boolean moveLeft = false;
        String str;
        while (right+length <= s.length()) {
            str = s.substring(right, right+length);
            if (map.containsKey(str)){
                map.put(str, map.get(str) -1);
                boolean isClear = true;
                for(Map.Entry<String, Integer> entry:map.entrySet()){
                    if (entry.getValue() > 0) {
                        isClear = false;
                        break;
                    }
                }
                if (isClear) {
                    // 全部都匹配上了
                    moveLeft = true;
                }
            }
            right++;

            while (moveLeft) {
                String strTmp = s.substring(left, left+length);
                if (map.containsKey(strTmp)) {
                    map.put(strTmp, map.get(str)+1);
                    if (map.get(strTmp) > 0) {
                        moveLeft = false;
                    }
                }
                if (right - left -1 == length * (words.length-1)) {
                    res.add(left);
                }
                left++;
            }
        }
        return res;
    }
    public static void main(String[] arguments) {
        String s = "barfoothefoobarman";
        String[] words = {"foo","bar"};
        Solution solution = new Solution();
        System.out.printf("" + solution.findSubstring(s, words));
    }
}
