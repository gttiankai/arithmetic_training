/**
 * Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
 *
 * Example:
 *
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 *
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 * */

package dynamic_programming.unique_binary_search_trees_96;

public class Solution {
    public int numTrees(int n) {
        if (n == 0) {
            return 0;
        }
        int[] dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                  dp[i] += dp[j-1]*dp[i-j];
            }

        }
        return dp[n];
    }
    public static void main(String[] arguments) {
        Solution solution = new Solution();
        System.out.println(solution.numTrees(3));
    }
}
