package hashTable.valid_anagram_242;

import java.util.Arrays;

public class Solution1 {
    /**
     * 排序法
     * Runtime: 5 ms, faster than 60.40% of Java online submissions for Valid Anagram.
     * Memory Usage: 38 MB, less than 51.02% of Java online submissions for Valid Anagram.
     * */
    public boolean isAnagram(String s, String t) {
        if (s.length() != s.length()) {
            return false;
        }
        char[] chars1 = s.toCharArray();
        char[] chars2 = t.toCharArray();
        Arrays.sort(chars1);
        Arrays.sort(chars2);

        return Arrays.equals(chars1, chars2);
    }
}
