/**
 * Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters
 *
 * represent different tasks. Tasks could be done without original order. Each task could be done in one interval.
 *
 * For each interval, CPU could finish one task or just be idle.
 *
 * However, there is a non-negative cooling interval n that means between two same tasks, there must be at least
 *
 * n intervals that CPU are doing different tasks or just be idle.
 *
 * You need to return the least number of intervals(时间间隔) the CPU will take to finish all the given tasks.
 *
 *
 *
 * Example:
 *
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 *
 *
 * Note:
 *
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 * */
package array.task_scheduler_621;

import java.util.HashMap;

public class Solution {
    /**
     * 我本来是想通过 Hash表的方式处理这个程序,但是其实每个task 的编号其实是不会影响
     * 调度的.
     * */
    public int leastInterval(char[] tasks, int n) {
        if (tasks == null || tasks.length == 0){
            return 0;
        }
        int ans = 0;
        HashMap<Character, Integer> hashMap = new HashMap<Character, Integer>();
        for (int i = 0; i < tasks.length; i++) {
            hashMap.put(tasks[i], hashMap.getOrDefault(tasks[i], 0) + 1);
        }
        while (hashMap.size() > 0) {
            if (hashMap.size() > n) {

            }
        }
        return 0;
    }

}
