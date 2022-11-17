/**
 * Given a non-empty array of integers, return the k most frequent elements.
 * 在非空数组中,返回 K 个最常见的(重复的)元素
 *
 * Example 1:
 *
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 *
 * Example 2:
 *
 * Input: nums = [1], k = 1
 * Output: [1]
 * Note:
 *
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 *
 * Your algorithm's time complexity must be better than O(n log n),
 *
 * where n is the array's size.
 *
 * */

package hashTable.top_k_frequent_elements_347;

import org.omg.PortableInterceptor.INACTIVE;
import sun.awt.datatransfer.DataTransferer;

import java.util.*;

public class Solution {
    /**
     *
     * Runtime: 13 ms, faster than 74.97% of Java online submissions for Top K Frequent Elements.
     * 这个算法是我自己想起来的
     *
     * */
    public List<Integer> topKFrequent(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return new ArrayList<>();
        }
        Hashtable<Integer, Integer> hashtable = new Hashtable<Integer, Integer>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
//            if (hashtable.contains(nums[i])) {
//                hashtable.put(nums[i], hashtable.get(nums[i]) + 1);
//            } else {
//                hashtable.put(nums[i], 1);
//            }

            hashtable.put(nums[i], hashtable.getOrDefault(nums[i], 0)+ 1);
        }
        List <Integer> list = new ArrayList<>();
        /**
         * 新建 Collections.sort 的方式进行排序,是很值得学习的.
         * */
        ArrayList<Map.Entry<Integer, Integer>> arrayList = new ArrayList(hashtable.entrySet());
        Collections.sort(arrayList, new Comparator<Map.Entry<Integer, Integer>>() {
            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                return o2.getValue().compareTo(o1.getValue());
            }
        });
        for (int i = 0; i < k; i ++) {
            list.add(arrayList.get(i).getKey());
        }
        return list;
    }

    public static void main(String[] arguments) {
        int[] nums = new int[]{1, 1, 1, 2, 2, 3};
        int k = 2;
        Solution solution = new Solution();
        List<Integer> ans = solution.topKFrequent(nums, k);
    }
}
