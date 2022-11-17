/**
 * Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the
 *
 * very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 *
 * Return the max sliding window.
 *
 * Example:
 *
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation:
 *
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.
 *
 * Follow up:
 * Could you solve it in linear time? O(n)
 *
 * */

package heap.sliding_window_maximum_239;

import java.util.ArrayDeque;
import java.util.Deque;

public class Solution {
    /**
     * 使用最直观的滑动窗口的计算方式,可以得到滑动窗口内的最大值.
     * 最坏的情况为: O(n^2)
     * */
    public int[] maxSlidingWindowSlow(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return nums;
        }
        int[] res = new int[nums.length-k+1];
        for (int i = 0; i < nums.length -k+1; i++) {
            int max = nums[i];
            for (int j = i; j < i+k; j++) {
                if (max < nums[j]){
                    max = nums[j];
                }
            }
            res[i] = max;
        }
        return res;
    }
    /**
     * 找一个 O(n)的算法,
     * 这个方式非常好,但是没有考虑到一种比较普遍的情况
     * unite test: {7, 2, 4} 2
     * output: [7, 7]
     * expect: [7, 4]
     *
     * 这个方法不行
     * */
    public int[] maxSlidingWindowFailed(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return nums;
        }

        int[] res = new int[nums.length-k+1];

        int max = nums[0];
        for (int i = 1; i < k; i++) {
            if (max < nums[i]) {
                max = nums[i];
            }
        }
        res[0] = max;
        for (int i = k; i < nums.length ; i++) {
            if (max < nums[i]) {
                max = nums[i];
            }
            res[i-k+1] = max;
        }
        return res;
    }


    public int[] maxSlidingWindowFailedAgain(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return nums;
        }

        int[] res = new int[nums.length-k+1];

        int maxIndex = 0;
        for (int i = 0; i < k; i++) {
            if (nums[maxIndex] < nums[i]) {
                maxIndex = i;
            }
        }
        res[0] = nums[maxIndex];
        for (int i = k; i < nums.length ; i++) {
            if (maxIndex + k > i) {
                if (nums[maxIndex] < nums[i]) {
                    maxIndex = i;
                }
            } else {
                /**
                 * 这个地方不能简单的进行替换,最大值要重新计算.
                 * unite test:
                 * input: [1, 3, 1, 2, 0, 5]  3
                 * output: [3, 3, 0, 5]
                 * expect: [3, 3, 2, 5]
                 *
                 *  这个算法再继续下去的话,就会演变成 O(n^2)的算法.
                 **/
                maxIndex = i;
            }
            res[i-k+1] = nums[maxIndex];
        }
        return res;
    }

    /**
     * 感觉这个方法使用双端队列的方式,将我没有实现的方法,进行了实现.
     *
     * 这代码还是比较复杂的.没有理解清楚
     * */
    public int[] maxSlidingWindow(int[] nums, int k) {

        if (nums == null|| nums.length == 0) {
            return new int[0];
        }
        int n = nums.length;

        int[] res = new int[n-k+1];
        int resIndex = 0;
        // q 中永远保存的是最大值的 index
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            // remove numbers out of range k
            while (!q.isEmpty() && q.peekFirst() < i-k+1){
                // 这种条件就是原来的最大值要舍弃了
                q.poll();
            }
            // remove smaller numbers in k range as they are useless
            while (!q.isEmpty() && nums[q.peekLast()] < nums[i]) {
                // 因为 nums[i], 比原来的值要大,所以这个值没有用了,要舍弃掉.
                q.pollLast();
            }
            // q contains index... res contains content
            q.offer(i);
            if (i >= k-1) {
                res[resIndex++] = nums[q.peekFirst()];// 这个就是结果了, 判断条件的意思是表明已经满足窗口了
            }
        }
        return res;
    }

    public static void main(String[] arguments) {
        int[] nums = {1,3,-1,-3,5,3,6,7};
        int k = 3;
        Solution solution = new Solution();
        int[] res = solution.maxSlidingWindow(nums, k);
        for (int item : res) {
            System.out.println(item);
        }
    }
}
