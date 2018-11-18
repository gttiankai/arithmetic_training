/**
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * <p>
 * Note:
 * <p>
 * The solution set must not contain duplicate triplets.
 * <p>
 * Example:
 * <p>
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * <p>
 * A solution set is:
 * [
 * [-1, 0, 1],
 * [-1, -1, 2]
 * ]
 */

package ThreeSum_15;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    /**
     * BF 方式：
     * O（n^3）的方式
     *
     * more smart solution?
     * 使用网上很通用的解法，可以非常快的解决问题
     *
     * 使用方法调用的方式解决这个问题，造成超时，所以需要重新写
     *
     *
     * */
    public static List<List<Integer>> threeSum(int[] nums) {
        if (null == nums || nums.length < 3) {
            return new ArrayList<List<Integer>>();
        }
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        // 排序
        Arrays.sort(nums);
        int length = nums.length;
        int target = 0;
        for (int i = 0; i < length; i++) {
            List<List<Integer>> item = twoSumSort(Arrays.copyOfRange(nums, i + 1, length),
                    target - nums[i]);
            if (null != item && 0 != item.size()) {
                for (List<Integer> list : item) {
                    list.add(0, nums[i]);
                    // 去重
                    if (!res.contains(list)) {
                        res.add(list);
                    }
                }
            }
        }
        return res;
    }

    /**
     * K-SUM问题的排序的解法
     * 最终的结果是不一样的，这个方式返回的是数组对，并不是标号
     * */
    public static List<List<Integer>> twoSumSort(int[] nums, int target) {
        if (nums == null || nums.length < 2) {
            return null;
        }
        int header = 0;
        int tail = nums.length - 1;
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        while (header < tail) {
            int sum = nums[header] + nums[tail];
            if (sum == target) {
                List<Integer> item = new ArrayList<Integer>();
                item.add(nums[header]);
                item.add(nums[tail]);
                header++;
                tail--;
                res.add(item);
            } else if (sum < target) {
                header++;
            } else {
                tail--;
            }
        }
        return res;
    }

    public static List<List<Integer>> threeSumQuick(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (null == nums || nums.length < 3) {
            return res;
        }
        // 对数组进行排序
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            // 去重
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            }
            int target = -nums[i];
            int low = i+1;
            int hight = nums.length-1;
            while (low < hight) {
                int sum =  nums[low] + nums[hight];
                if (target == sum) {
                    //这种方式是非常耗时的，只要进行了 contains 操作，就会出现超时的问题，所以不能使用这个函数
//                    List<Integer> item= Arrays.asList(nums[i], nums[low], nums[hight]);
//                    if (!res.contains(item)){
//                        res.add(item);
//                    }
                    res.add(Arrays.asList(nums[i], nums[low], nums[hight]));
                    while (low < hight && nums[low] == nums[low+1]) low++;
                    while (low < hight && nums[hight] == nums[hight-1]) hight--;
                    low++;
                    hight--;
                } else if (sum < target) {
                    low++;
                } else {
                    hight--;
                }
            }
        }
        return res;
    }

    public static void main(String[] arguments) {
        int[] nums = {-2,0,0,2,2};
        System.out.println(threeSumQuick(nums));
    }
}
