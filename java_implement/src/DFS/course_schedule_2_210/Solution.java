/**
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1,
 *
 * which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you
 *
 * should take to finish all courses.
 *
 * There may be multiple correct orders, you just need to return one of them. If it is impossible to finish
 *
 * all courses, return an empty array.
 *
 * Example 1:
 *
 * Input: 2, [[1,0]]
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you should have finished
 *              course 0. So the correct course order is [0,1] .
 * Example 2:
 *
 * Input: 4, [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,1,2,3] or [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
 *              courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
 *              So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
 * Note:
 *
 * The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about
 *
 * how a graph is represented.
 *
 * You may assume that there are no duplicate edges in the input prerequisites.
 *
 * */
package DFS.course_schedule_2_210;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    /**
     * 下面的算法是参考以前的事情，发现以前使用的算法，不能解决这个问题，最主要的原因是算法的设计思路上不能支持这种记录路径的问题
     *
     * */
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        ArrayList[] graph = new ArrayList[numCourses];
        boolean[] visited = new boolean[numCourses];
        List<Integer> ans = new ArrayList<>();

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
            if (!DFS(graph, visited, i, ans)) {
                return null;
            }
        }
        return ans.stream().mapToInt(x->x).toArray();

    }
    /**
     * course 代表从第几节课开始进行 DFS 的遍历.
     * */
    private boolean DFS(ArrayList[] graph, boolean[] visited, int course, List<Integer> ans) {
        if (visited[course]){
            // 已经成了环了，所以直接返回
            return false;
        } else {
            visited[course] = true;
            ans.add(course);
        }
        for (int i = 0; i < graph[course].size(); i++) {
            if (!DFS(graph, visited, (int)graph[course].get(i), ans)){
                return false;
            }
        }
        // 经过上面的递归的遍历，还没有覆盖， 则这个就是错误的。
        visited[course] = false;
        return true;
    }
    public static void main(String[] arguments) {
        int numCourses = 2;
        int[][] prerequisites = new int[][]{{1,0}};

        Solution solution = new Solution();
        int[] ans = solution.findOrder(numCourses, prerequisites);
        for (Integer item:ans) {
            System.out.println(item);
        }
    }
}
