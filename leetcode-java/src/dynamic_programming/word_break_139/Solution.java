/**
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
 *
 * determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 * Note:
 *
 * The same word in the dictionary may be reused multiple times in the segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * Example 1:
 *
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet code".
 * Example 2:
 *
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
 *              Note that you are allowed to reuse a dictionary word.
 * Example 3:
 *
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 *
 *
 * */

package dynamic_programming.word_break_139;

import java.util.ArrayList;
import java.util.List;

public class Solution {

    // 子问题是 dp[i]:表示 s 从0到 i 的位置,
    public boolean wordBreak(String s, List<String> wordDict) {
        if ( s == null || wordDict == null) {
            return false;
        }
        int n = s.length();
        boolean[] dp = new boolean[n+1];
        dp[0] = true;
        for (int bound = 1; bound <= n; bound++ ) {
            for (int i = 0; i < bound; i++) {
                if(dp[i] && wordDict.contains(s.substring(i, bound))){
                    dp[bound] = true;
                    // 如果已经找到了,就可以停止寻找了,不用再继续了.
                    break;
                }
            }
        }
        return dp[n];
    }
    public static void main(String[] arguments) {
        String s = "leetcode";
        List<String> wordDict = new ArrayList<>();
        wordDict.add("leet");
        wordDict.add("code");
        Solution solution = new Solution();
        System.out.printf("" + solution.wordBreak(s, wordDict));
    }

}
