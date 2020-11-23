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

package hashTable.substring_whith_concatenation_of_all_words_30;

import java.util.*;

public class Solution {
    /**
     * 经过反复的调试,发现已经失败了,并不能很好的解决这个问题,
     * 我这次使用的滑动窗口法,没有成功
     *
     * */
    public List<Integer> findSubstringFailed(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        if (s == null || words == null || words[0].length() > s.length()) {
            return res;
        }
        int left = 0;
        int right = 0;
        int wordLength = words[0].length();
        Map<String, Integer> map = new HashMap<String, Integer>();
        for (String word: words) {
            map.put(word, map.getOrDefault(word, 0) +1);
        }
        int counter = map.size();
        boolean moveLeft = false;
        String str;
        while (right <= s.length()-wordLength) {
            str = s.substring(right, right+wordLength);
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
                String strTmp = s.substring(left, left+wordLength);
                if (map.containsKey(strTmp)) {
                    map.put(strTmp, map.get(str)+1);
                    if (map.get(strTmp) > 0) {
                        moveLeft = false;
                    }
                    if (right - left -1 == wordLength * (words.length-1)) {
                        res.add(left);
                    }
                    left++;
                } else {
                    left++;
                }
            }
        }
        return res;
    }

    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new LinkedList<>();
        if (words.length == 0 || s.length() < words.length * words[0].length()) {
            return res;
        }
        int length = s.length();
        int wordSize = words.length;
        int wordLen = words[0].length();
        Map<String, Integer> map = new HashMap<>();
        Map<String, Integer> curMap = new HashMap<>();
        for (String word : words) {
            map.put(word, map.getOrDefault(word, 0) + 1);
        }
        String str = null, tmp = null;
        /*
        * 为啥只需要循环 wordLen次?
        * 这是因为内循环中是每次以wordLen作为循环的增量的.
        * 循环wordLen次,就就可以保证,每次以不同的起始点进行遍历
        * */
        for (int i = 0; i < wordLen; i++) {
            int count = 0; // remark: reset count
            int start = i;
            for (int j = i; j + wordLen <= length; j += wordLen) {
                str = s.substring(j, j + wordLen);
                if (map.containsKey(str)) {
                    // curMap 记录的是遍历过,并且有效的字符串
                    curMap.put(str, curMap.getOrDefault(str, 0) + 1);

                    if (curMap.get(str) <= map.get(str)) {
                        count++;
                    }
                    while (curMap.get(str) > map.get(str)) {
                        tmp = s.substring(start, start + wordLen);
                        curMap.put(tmp, curMap.get(tmp) - 1);
                        start += wordLen;
                        if (curMap.get(tmp) < map.get(tmp)) {
                            count--;
                        }
                    }
                    if (count == wordSize) {
                        res.add(start);
                        tmp = s.substring(start, start + wordLen);
                        curMap.put(tmp, curMap.get(tmp) - 1);
                        start += wordLen;
                        count--;
                    }
                } else {
                    // 因为题目中有要求, 子串要与words中的单词完全匹配,并且中间不能有其他字符
                    curMap.clear();
                    count = 0;
                    start = j + wordLen;
                }
            }
            curMap.clear();
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
