/**
 * Once you pay the cost, you can either climb one or two steps.
 * You need to find minimum cost to reach the top of the floor,
 * and you can either start from the step with index 0, or the step with index 1.
 *
 * Example 1:
 * Input: cost = [10, 15, 20]
 * Output: 15
 * Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
 * Example 2:
 * Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 * Output: 6
 * Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
 * Note:
 * cost will have a length in the range [2, 1000].
 * Every cost[i] will be an integer in the range [0, 999].
 * */
package dynamic_programming.min_cost_climbing_stairs_746;

public class Solution {
    public static int minCostClimbingStairs(int[] cost) {
        if (null == cost) {
            return 0;
        }
        int len = cost.length;
        if (len == 0) {
            return 0;
        }
        int[] map = new int[len];
        map[0] = cost[0];
        map[1] = cost[1];
        /**
         * map[i]:爬上 i 级台阶需要的花费.
         * 结果是完成 i 级楼梯需要的花费,这两个问题不同同一个问题.
         * 但是这两个问题又有一定的联系,完成 i 级楼梯,只需要爬上 i-1 或者 i-2 级台阶就可以了.
         * 这是因为一次跨越的台阶数量可以是1,也可以是2.
         * map[i] = cost[i] + min{map[i-1], map[i-2]}
         */
        for (int i = 2; i < len; i++) {
            map[i] = cost[i] + Math.min(map[i-1], map[i-2]);
        }
        // 主要是最终可以一步或者两步,最后这个比较麻烦.
        return Math.min(map[len-1], map[len-2]);

    }
    public static void main(String[] arguments) {
        int[] cost =  {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        int[] cost1 = {10, 15, 20};
        System.out.println(minCostClimbingStairs(cost1));
    }
}
