package array.task_scheduler_621;

import java.util.Arrays;

public class Solution2 {
    /**
     * Runtime: 3 ms, faster than 88.95% of Java online submissions for Task Scheduler.
     * reference url:https://www.cnblogs.com/grandyang/p/7098764.html
     * */
    public int leastInterval(char[] tasks, int n) {
        if (tasks == null || tasks.length == 0) {
            return 0;
        }
        int[] map = new int[26];
        for (char c: tasks){
            map[c - 'A']++;
        }
        Arrays.sort(map);
        int max = map[25];
        int i = 25;
        int size = 1;
        while ( i > 0 ) {
            if (map[i] == map[i-1]){
                size++;
                i--;
            } else {
                break;
            }
        }
        return Math.max(tasks.length, (max -1)*(n + 1) + size);


    }
    public static void main(String[] arguments){
        char[] tasks = new char[]{'A', 'B','A', 'B','A', 'B'};
        int n = 2;
        Solution2 solution = new Solution2();
        System.out.println(solution.leastInterval(tasks, n));
    }
}
