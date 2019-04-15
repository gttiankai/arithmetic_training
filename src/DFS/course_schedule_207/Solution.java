/**
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1,
 *
 * which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 *
 * Example 1:
 *
 * Input: 2, [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 *              To take course 1 you should have finished course 0. So it is possible.
 *
 * Example 2:
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 *              To take course 1 you should have finished course 0, and to take course 0 you should
 *              also have finished course 1. So it is impossible.
 * Note:
 *
 * The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about
 *
 * how a graph is represented.
 *
 *
 * You may assume that there are no duplicate edges in the input prerequisites.
 *
 * */

package DFS.course_schedule_207;

import java.util.*;

public class Solution {
    /**
     * 这个思路和我的思路是一致的，但是这个方式，别人做出来了。欠缺的点是没有理解清楚
     */

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList[] graph = new ArrayList[numCourses];
        boolean[] visited = new boolean[numCourses];

        for (int i = 0; i < numCourses; i++) {
            graph[i] = new ArrayList();
        }
        /**
         * graph[i]代表 i 课程之后能够学习到的课程,也就是以 i 为前置课程的所有的课程.
         * */
        for (int i = 0; i < prerequisites.length; i++) {
            graph[prerequisites[i][1]].add(prerequisites[i][0]);
        }
        /**
         * 这个保证了所有的课程都是可以遍历到的
         * */
        for (int i = 0; i < numCourses; i++) {
            if (!DFS(graph, visited, i)) {
                return false;
            }
        }
        return true;
    }
    /**
     * course 代表从第几节课开始进行 DFS 的遍历.
     * */
    private boolean DFS(ArrayList[] graph, boolean[] visited, int course) {
        if (visited[course]){
            // 已经成了环了，所以直接返回
            return false;
        }else {
            visited[course] = true;
        }
        for (int i = 0; i < graph[course].size(); i++) {
            if (!DFS(graph, visited, (int)graph[course].get(i))){
                return false;
            }
        }
        // 经过上面的递归的遍历，还没有覆盖， 则这个就是错误的。
        visited[course] = false;
        return true;
    }


    /**
     * 讲真的，这个算法有点看不懂，所以后面需要加强
     * 今天恍然大悟，这个算法讲的是BFS，并不是DFS。
     * */
    public boolean canFinishF(int numCourses, int[][] prerequisites) {
        int[][] matrix = new int[numCourses][numCourses];
        int[] indegree = new int[numCourses];
        for (int i = 0; i < prerequisites.length; i++) {
            int ready = prerequisites[i][0];
            int pre = prerequisites[i][1];
            if (matrix[pre][ready] == 0) {
                //duplicate case
                indegree[ready]++;
            }
            matrix[pre][ready] = 1;
        }
        int count = 0;
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < indegree.length; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
            }
        }
        while (!queue.isEmpty()) {
            int course = queue.poll();
            count++;
            for (int i = 0; i < numCourses; i++) {
                if (matrix[course][i] != 0) {
                    if (--indegree[i] == 0) {
                        queue.offer(i);
                    }
                }
            }
        }
        return count == numCourses;
    }
}
