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
        if (s == null || wordDict == null) {
            return false;
        }
        int n = s.length();
        boolean[] dp = new boolean[n+1];
        // 这个初始值的设定非常重要,而且不是根据推理得出的,而是根据下面的代码,
        // dp[0]必须是 true,如果是 false,则永远返回 false.
        dp[0] = true;
        for (int window = 1; window <= n; window++) {
            for (int j = 0; j < window; j++) {
                if (dp[j] && wordDict.contains(s.substring(j,window))){
                    dp[window] = true;
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
