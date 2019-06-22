/**
 * Given a list of non negative integers, arrange them such that they form the largest number.
 * <p>
 * Example 1:
 * <p>
 * Input: [10,2]
 * Output: "210"
 * Example 2:
 * <p>
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 * Note: The result may be very large, so you need to return a string instead of an integer.
 */

package sort.largest_number_179;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution {

    /**
     *
     * Unite test: [121, 12] , [824, 8247]
     *
     *
     * */
    public String largestNumber(int[] nums) {
        if (nums == null || nums.length == 0) {
            return "";
        }
        int n = nums.length;

        Comparator<String> comparator = new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                int i = 0;
                while (i < o1.length() && i < o2.length()) {
                    if (o1.charAt(i) == o2.charAt(i)) {
                        i++;
                    } else {
                        return o2.charAt(i) - o1.charAt(i);
                    }
                }
                if (o1.length() == o2.length()) {
                    return 0;
                } else if (o1.length() > o2.length()) {
                    int n = o1.length();
                    return o1.charAt(0) - o1.charAt(n-1);
                } else {
                    // o1.length < o2.length
                    /**
                     * 此处得的代码过不了 [121, 12]. 这个测试例
                     * */
                    int n = o2.length();
                    return o2.charAt(n-1) - o2.charAt(0);
                }

            }
        };


        PriorityQueue<String> priorityQueue = new PriorityQueue<>(comparator);
        String[] strings = new String[n];
        for (int i = 0; i < n; i++) {
            priorityQueue.add(String.valueOf(nums[i]));
        }
        StringBuilder ans = new StringBuilder();
        while (priorityQueue.size() > 0) {
            ans = ans.append(priorityQueue.poll());
        }
        /**
         * 遇到一个特殊的测试例
         * unite test:
         *      input: [0, 0]
         *      output: 00
         *      expect: 0
         * FOCUS: 特殊处理尾部
         * */

        String res = ans.toString();
        while (res.startsWith("0") && res.length() > 1) {
            res = res.substring(1);
        }
        return res;
    }

    public static void main(String[] args) {
        //int[] nums = {3,30,34,5,9};
        //int[] nums = {824, 8247};
        int[] nums = {121, 12};
        Solution solution = new Solution();
        String ans = solution.largestNumber(nums);
        System.out.println(ans);
    }
}
