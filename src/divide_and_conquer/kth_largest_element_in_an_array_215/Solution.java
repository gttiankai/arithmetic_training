/**
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order,
 *
 * not the kth distinct element.
 *
 * Example 1:
 *
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * Example 2:
 *
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 *
 * */
package divide_and_conquer.kth_largest_element_in_an_array_215;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution {
    /**
     * 这个题目代表一系列的题目:选择问题,有很多中做法.
     *
     *
     * */


    /**
     *  果然和我想的一样,使用最直接的方式,是可以直接解决这个问题的.
     * */
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length-k];
    }

    /**
     * 使用优先队列的方式创建大顶堆,然后取出大顶堆的第 n 个元素就可以了.
     * 这个方法比上一个方法,更耗时,而且更耗 CPU
     */

    public int findKthLargestPriority(int[] nums, int k) {
        final PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });

        for (int item: nums) {
            priorityQueue.offer(item);
        }
        for (int i = 0; i < k-1; i++) {
            int item = priorityQueue.poll();
            System.out.println("value: " + item);
        }
        return priorityQueue.peek();
    }

    public int findKthLargestPrioritySelect(int[] nums, int k) {
        k = nums.length - k;
        int lo = 0;
        int hi = nums.length - 1;
        while (lo < hi) {
            final int j = partition(nums, lo, hi);
            if(j < k) {
                lo = j + 1;
            } else if (j > k) {
                hi = j - 1;
            } else {
                break;
            }
        }
        return nums[k];
    }

    private int partition(int[] nums, int low, int hig) {

        int i = low;
        int j = hig + 1;
        while (true) {
            while (i < hig && less(nums[++i], nums[low]));
            while (j > low && less(nums[low], nums[--j]));
            if (i >= j) {
                break;
            }
            swap(nums, i , j);
        }
        swap(nums, low, j);
        return j;
    }

    private void swap(int[] nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    private boolean less(int a, int b) {
        return a < b;
    }
    /**
     * 这个算法比较好懂,基于选择的算法
     * */
    public int select(int[] nums, int k) {
        for (int i = 0; i < k; i++) {
            int maxIndex = i;
            int maxValue = nums[i];
            for (int j = i+1; j < nums.length; j++ ) {
                if (nums[j] > maxValue) {
                    maxIndex = j;
                    maxValue = nums[j];
                }
            }
            swap(nums, i , maxIndex);

        }
        return nums[k-1];
    }



    public static void main(String[] arguments) {
        int[] nums = {3,2,1,5,6,4};
        int k = 2;
        Solution solution = new Solution();
        System.out.printf("" + solution.select(nums, k));
    }
}
