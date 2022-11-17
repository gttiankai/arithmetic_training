package hashTable.first_unique_character_in_a_string_387;

public class Solution1 {
    /**
     * Runtime: 8 ms, faster than 85.97% of Java online submissions for First Unique Character in a String.
     * Memory Usage: 36.8 MB, less than 99.73% of Java online submissions for First Unique Character in a String.
     * 
     * 其实这个接法,以前也见过,但是没有完全理解,这里有联系了一遍.
     * */
    public int firstUniqChar(String s) {
        if (s == null || s.length() == 0) {
            return -1;
        }
        int[] map = new int[26];
        for(int i = 0; i < s.length(); i++) {
            map[s.charAt(i) - 'a']++; 
        }
        // 这个是按照字符串得顺序进行遍历得,所以可以保证返回得时第一个出现非重复得字符
        for(int i = 0; i < s.length(); i++) {
            if(map[s.charAt(i) - 'a'] == 1){
               return i; 
            }
        }
        return -1;
    }
}
