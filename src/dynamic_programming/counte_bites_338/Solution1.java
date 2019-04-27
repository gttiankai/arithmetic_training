/**
 * Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num
 *
 * calculate the number of 1's in their binary representation and return them as an array.
 *
 * Example 1:
 *
 * Input: 2
 * Output: [0,1,1]
 * Example 2:
 *
 * Input: 5
 * Output: [0,1,1,2,1,2]
 * Follow up:
 *
 * It is very easy to come up with a solution with run time O(n*sizeof(integer)).
 *
 * But can you do it in linear time O(n) /possibly in a single pass?
 *
 * Space complexity should be O(n).
 *
 * Can you do it like a boss? Do it without using any builtin function like
 *
 * __builtin_popcount in c++ or in any other language.
 *
 * */
package dynamic_programming.counte_bites_338;

public class Solution1 {
    /**
     * Runtime: 3 ms, faster than 15.79% of Java online submissions for Counting Bits.
     *
     * 使用自己的思路解决的问题
     *
     * */
    public int[] countBits(int num) {
        if (num == 0) {
            return new int[]{0};
        }
        int[] ans = new int[num+1];
        for (int i = 0; i <= num; i++) {
            ans[i] = calculateNumber(i);
        }
        return ans;
    }

    private int calculateNumber(int num) {
        int ans = 0;
        while (num > 0) {
            int remainder = num % 2;
            if (remainder == 1) {
                ans++;
            }
            num = num / 2;
        }
        return ans;
    }
    public static void main(String[] arguments) {
        int num = 5;
        Solution solution = new Solution();
        int[] res = solution.countBits(num);
        for (Integer item : res) {
            System.out.println(item);
        }
    }
}
