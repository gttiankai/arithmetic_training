/**
 * Given a string, find the first non-repeating character in it and return
 *
 * it's index. If it doesn't exist, return -1.
 *
 * Examples:
 *
 * s = "leetcode"
 * return 0.
 *
 * s = "loveleetcode",
 * return 2.
 * Note: You may assume the string contain only lowercase letters.
 * */
package hashTable.first_unique_character_in_a_string_387;

import java.util.HashMap;
import java.util.Map;

public class Solution {
    /*
    * Runtime: 41 ms, faster than 32.80% of Java online submissions for First Unique Character in a String.
    * Memory Usage: 38.5 MB, less than 90.80% of Java online submissions for First Unique Character in a String.
    * 使用得 hashmap 得方式解决得这个问题,但是效率不高.
    *
    * 还有注意特殊条件得情况
    *
    * unite: "", "cc"
    * */
    public int firstUniqChar(String s) {
        if (s == null || s.length() == 0) {
            return -1;
        }
        int ans = s.length();
        HashMap<Character, Integer> hashtable = new HashMap<Character, Integer>();
        for (int i = 0; i < s.length(); i++) {
            hashtable.put(s.charAt(i), hashtable.getOrDefault(s.charAt(i), 0) + 1);
        }
        for (Map.Entry<Character, Integer> entry: hashtable.entrySet()) {
            if (entry.getValue() == 1 ) {
                Character tmp = entry.getKey();
                if (s.indexOf(String.valueOf(tmp)) < ans){
                    ans = s.indexOf(String.valueOf(tmp));
                }

            }
        }
        if ( ans == s.length()) {
            return -1;
        }else {
            return ans;
        }
    }

    public static void main(String[] args) {
        String s= "loveleetcode";
        String s1 = "cc";
        Solution solution = new Solution();
        System.out.println(solution.firstUniqChar(s1));
    }
}
