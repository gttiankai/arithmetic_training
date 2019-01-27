/**
 * Given a string s and a non-empty string p, find all the start indices of p's
 *
 * anagrams in s.
 *
 * Strings consists of lowercase English letters only and the length of both strings s
 *
 * and p will not be larger than 20,100.
 *
 * The order of output does not matter.
 *
 * Example 1:
 *
 * Input:
 * s: "cbaebabacd" p: "abc"
 *
 * Output:
 * [0, 6]
 *
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * Example 2:
 *
 * Input:
 * s: "abab" p: "ab"
 *
 * Output:
 * [0, 1, 2]
 *
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 *
 * */
package hashTable.find_all_anagrams_in_string_438;

import java.util.*;

public class Solution {
    public static List<Integer> findAnagramsFailed(String s, String p) {
        List<Integer> res = new ArrayList<>();
        if (s == null ||
                s.length() == 0 ||
                p == null ||
                p.length() == 0 ||
                p.length() > s.length()) {
            return res;
        }
        int window = p.length();
        char[] sArray = s.toCharArray();
        List<Character> list = new ArrayList<>();
        for (char item : p.toCharArray()) {
            list.add(item);
        }
        for (int i = 0; i < s.length() - window; i++) {
            boolean neeAdd = true;
            for (int j = i; j < i + window; j++) {
                // 这个题目最难得地方在于怎么判断是字母异位词
                if (!list.contains(sArray[j])) {
                    neeAdd = false;
                    break;
                }
            }
            if (neeAdd) {
                res.add(i);
            }
        }
        return res;
    }

    /**
     * 滑动窗口法
     *
     * */

    public List<Integer> findAnagrams(String s, String t) {
        List<Integer> result = new LinkedList<>();
        if(t.length()> s.length()) {
            return result;
        }
        Map<Character, Integer> map = new HashMap<>();
        for(char c : t.toCharArray()){
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        int counter = map.size();

        int begin = 0, end = 0;


        while(end < s.length()){
            char c = s.charAt(end);
            if( map.containsKey(c) ){
                map.put(c, map.get(c)-1);
                if(map.get(c) == 0) {
                    counter--;
                }
            }
            end++;

            while(counter == 0){
                char tempc = s.charAt(begin);
                if(map.containsKey(tempc)){
                    map.put(tempc, map.get(tempc) + 1);
                    if(map.get(tempc) > 0){
                        counter++;
                    }
                }
                if(end-begin == t.length()){
                    result.add(begin);
                }
                begin++;
            }

        }
        return result;
    }


    public static void main(String[] arguments) {
        String s = "cbaebabacd";
        String p = "abc";
        Solution solution = new Solution();
        System.out.printf("" + solution.findAnagrams(s, p));
    }
}
