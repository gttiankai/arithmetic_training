package array.task_scheduler_621;

import java.util.Arrays;

public class Solution1 {
    public int leastInterval(char[] tasks, int n) {
        int[] map = new int[26];
        for (char c : tasks) {
            map[c - 'A']++;
        }
        Arrays.sort(map);
        int time = 0;
        while (map[25] > 0) {
            int i = 0;
            // i i<= n : 这个是因为相同的任务要间隔 n个时间
            while (i <= n) {
                if (map[25] == 0) {
                    break;
                }
                // map[25 -i]:  保证map[25-i] 为 0 时, time和 i 增加
                // 但是 map[25-i]不减少,其实就是对应于题目解释的 idle的情况
                if (i < 26 && map[25 - i] > 0) {
                    map[25 - i]--;
                }
                time++;
                i++;
            }
            Arrays.sort(map);
        }
        return time;
    }
    public static void main(String[] arguments){
        char[] tasks = new char[]{'A', 'B','A', 'B','A', 'B'};
        int n = 2;
        Solution1 solution = new Solution1();
        System.out.println(solution.leastInterval(tasks, n));
    }
}
