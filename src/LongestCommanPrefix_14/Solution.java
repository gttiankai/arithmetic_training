/* *
* Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
* */

package LongestCommanPrefix_14;

public class Solution {

    /**
     * BF solution: 使用暴力的方式
     * 1. 选择第一个string 的第一个字符作为前缀进行遍历，如果都有该字符，则继续
     * 进行下一轮的遍历，如果没有直接返回空。
     * 2. 选择第一个string的前两个字符作为前缀进行遍历......
     * */
    public static String longestCommonPrefix(String[] strs) {

        if (null == strs) {
            return "";
        }
        int length =  strs.length;
        if (length == 0) {
            return "";
        }
        if (length == 1) {
            return strs[0];
        }
        String prePrefix = "";
        for(int i = 0; i < strs[0].length(); i++){
            String prefix = strs[0].substring(0,i+1);
            for(int j = 1; j < length; j++) {
                if (!strs[j].startsWith(prefix)){
                   return prePrefix;
                }
            }
            prePrefix = prefix;
        }
        return prePrefix;
    }

    public static void main(String[] arguments) {
        String[] strs = {"c", "c"};
        System.out.println(longestCommonPrefix(strs));
    }
}
