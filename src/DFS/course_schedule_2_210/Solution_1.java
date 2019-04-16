package DFS.course_schedule_2_210;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution_1 {
    private boolean isPossible = true;
    private int WHITE = 1;
    private int GRAY = 2;
    private int BLACK = 3;

    private Map<Integer, Integer> color = new HashMap<Integer, Integer>();
    private Map<Integer, List<Integer>> adjList = new HashMap<Integer, List<Integer>>();
    private List<Integer> ans = new ArrayList<>();


    public int[] findOrder(int numCourses, int[][] prerequisites) {
        initGrap(numCourses,prerequisites);
        for (int i = 0; i < numCourses; i++) {
            if (color.get(i) == WHITE) {
                DFS(i);
            }
        }
        int[] order;
        if(this.isPossible) {
            order = new int[numCourses];
            for (int i = 0; i < numCourses; i++) {
                // 这个顺序很重要,要将数组倒叙输出.
                order[i] = ans.get(numCourses-i-1);
            }
        } else {
            order=  new int[0];
        }
        return order;
    }

    private void DFS(int node){
        if (!this.isPossible) {
            return;
        }
        this.color.put(node, GRAY);
        for (Integer neighbor: this.adjList.getOrDefault(node, new ArrayList<>())){
            if (color.get(neighbor) == WHITE) {
                DFS(neighbor);
            } else if (color.get(neighbor) == this.GRAY){
                this.isPossible = false;
            }
        }
        color.put(node, BLACK);
        ans.add(node);

    }
    private void initGrap(int numCourses, int[][] prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            color.put(i, WHITE);
        }
        for (int i = 0; i < prerequisites.length;i++) {
            int dest = prerequisites[i][0];
            int src = prerequisites[i][1];
            List tmp =  adjList.getOrDefault(src, new ArrayList<>());
            tmp.add(dest);
            adjList.put(src, tmp);
        }
    }

}
