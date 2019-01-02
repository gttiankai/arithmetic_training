/**
 * Given an array of strings, group anagrams together.
 *
 * Example:
 *
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 *   ["ate","eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * Note:
 *
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 这个题目学到的是
 * */
package group_anagrams_49;

import java.util.*;

public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs == null || strs.length == 0) {
            return new ArrayList<>();
        }
        HashMap<String, List> map = new HashMap<>();
        for (String str:
             strs) {
            char[] charArray = str.toCharArray();
            // 主要是使用了排序的操作,
            Arrays.sort(charArray);
            String key = String.valueOf(charArray);
            //  下面这两部还是挺好的,直接可以可以在后面借鉴下
            if (!map.containsKey(key)) {
                map.put(key, new ArrayList());
            }
            // 可以借鉴的还有就是Java系统提供的结构
            map.get(key).add(str);
        }
        return new ArrayList(map.values());
    }
}
