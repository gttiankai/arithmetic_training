/**
 *
 * Given a string s, partition s such that every substring of the partition
 *
 * is a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * Example:
 *
 * Input: "aab"
 * Output:
 * [
 *   ["aa","b"],
 *   ["a","a","b"]
 * ]
 *
 * */

package backtracking.palindrome_partitioning_131;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    /**
     * Runtime: 3 ms, faster than 65.68% of Java online submissions for Palindrome Partitioning.
     * Memory Usage: 37.6 MB, less than 99.97% of Java online submissions for Palindrome Partitioning.
     * */
    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        if (s == null || s.length() == 0) {
            return ans;
        }
        backTrack(ans, new ArrayList<>(), s, 0);
        return ans;
    }

    private void backTrack(List<List<String>> ans, List<String> tmpList, String s, int index) {
        if (index == s.length()) {
            ans.add(new ArrayList<String>(tmpList));
            return;
        }
        for (int i = 0; i < s.length() - index; i++) {
            String subString = s.substring(index, index + i +1);
            if(isPalindrome(subString)) {
                tmpList.add(subString);
                backTrack(ans, tmpList, s, index+i+1);
                tmpList.remove(tmpList.size()-1);
            }
        }
    }

    private boolean isPalindrome(String subString) {
        int left = 0;
        int right = subString.length()-1;
        while (left < right) {
            if (subString.charAt(left) != subString.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    public static void main(String[] arguments) {
        String s = "aab";
        Solution solution = new Solution();
        solution.isPalindrome("aa");
        System.out.println(solution.partition(s));
    }
}
