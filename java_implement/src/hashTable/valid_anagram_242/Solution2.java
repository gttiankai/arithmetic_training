package hashTable.valid_anagram_242;

public class Solution2 {
    /**
     * Runtime: 7 ms, faster than 32.43% of Java online submissions for Valid Anagram.
     * Memory Usage: 37.5 MB, less than 64.40% of Java online submissions for Valid Anagram.
     * Next challenges:
     *
     * 这个算法还是挺好的
     *
     * */
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()){
            return false;
        }
        int[] map = new int[26];
        for (Character character: s.toCharArray()) {
            map[character - 'a']++;
        }
        for (Character character: t.toCharArray()) {
            map[character -  'a']--;
            if ( map[character -  'a'] < 0) {
                return false;
            }
        }
        return true;

    }
}
