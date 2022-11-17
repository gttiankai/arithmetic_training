package sort.largest_number_179;

import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution1 {
    public String largestNumber(int[] nums) {
        /**
         * Runtime: 5 ms, faster than 60.97% of Java online submissions for Largest Number.
         * Memory Usage: 36.6 MB, less than 89.71% of Java online submissions for Largest Number.
         *
         * */
        if (nums == null || nums.length == 0) {
            return "";
        }
        int n = nums.length;
        /*
        * FOCUS:
        *   1.这个方案比较直接,直接比较两种方式比较大,避免了自己得写法中,相同前缀得数字得判断大小问题,
        *     有的时候越直接得方法越有效
        *   2.还有一个需要注意得时候,有效队列默认小的在前面,也就是说是升序排列,这一点需要注意.
        *
        * */
        Comparator<String> comparator = new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                String order1 = o1+ o2;
                String order2 = o2+ o1;
                return order2.compareTo(order1);
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
        if (ans.toString().startsWith("0")) {
            return "0";
        } else {
            return ans.toString();
        }
    }
}
