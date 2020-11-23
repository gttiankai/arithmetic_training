/**
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 * <p>
 * Note:
 * <p>
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 * <p>
 * Example 1:
 * <p>
 * Input: [2,2,1]
 * Output: 1
 * Example 2:1
 * <p>
 * Input: [4,1,2,1,2]
 * Output: 4
 * 要求: 时间复杂度 O(n), 空间复杂度:不适用额外的内存
 */
package single_number_136;

import java.util.Arrays;
import java.util.HashSet;

public class Solution {
    // 第一个办法是排序, 但是时间复杂度会高一点,及时使用优秀的排序算法,但是也不会达到O(n)
    public int singleNumberSort(int[] nums) {
        // 由于题目中一定提到,是非空的序列,所以不用在做校验了
//        if (nums == null || nums.length == 0) {
//            return
//        }
        Arrays.sort(nums);
        //  这样写的目的是为了更好的处理
        for (int i = 1; i < nums.length; i += 2) {
            if (nums[i - 1] != nums[i]) {
                return nums[i - 1];
            }
        }
        return nums[nums.length - 1];
    }

    public int singleNumberHash(int[] nums) {
        HashSet<Integer> array = new HashSet<>();
        for (int item : nums) {
            if (array.contains(item)) {
                array.remove(item);
            } else {
                array.add(item);
            }
        }
        return array.iterator().next();
    }

    // 终于找到我需要的算法了.就是使用数学的方式
    // nums = {a,a ,b, b, c, c, d}
    // d = 2 * (a+b+c+d) - (a+a+b+b+c+c+d)
    // 时间复杂度: O(n)
    // 空间复杂度: O(n)
    public int singleNumberMath(int[] nums) {
        HashSet<Integer> array = new HashSet<>();
        int sum = 0;
        for (int item : nums) {
            array.add(item);
        }
        for (Integer item : array) {
            sum += item * 2;
        }
        for (int item : nums) {
            sum = sum - item;
        }
        return sum;
    }

    // 终极的做法终于有了, 使用异或操作
    // 使用异或操作, 可以有效的消除重复的数据, 在这个题目中使用异或操作中还是比较合适的.
    public int singleNumber(int[] nums) {
        int res = nums[0];
        for (int i = 0; i < nums.length; i++) {
            res ^= nums[i];
        }
        return res;
    }
}
