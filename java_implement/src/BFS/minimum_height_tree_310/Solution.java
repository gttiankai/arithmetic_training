/**
 * For an undirected graph with tree characteristics, we can choose any node as the root.
 *
 * The result graph is then a rooted tree. Among all possible rooted trees, those with
 *
 * minimum height are called minimum height trees (MHTs). Given such a graph, write a
 *
 * function to find all the MHTs and return a list of their root labels.
 *
 * Format
 * The graph contains n nodes which are labeled from 0 to n - 1. You will be given the
 *
 * number n and a list of undirected edges (each edge is a pair of labels).
 *
 * You can assume that no duplicate edges will appear in edges. Since all edges are
 *
 * undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 *
 * Example 1 :
 *
 * Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 *
 *         0
 *         |
 *         1
 *        / \
 *       2   3
 *
 * Output: [1]
 * Example 2 :
 *
 * Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 *
 *      0  1  2
 *       \ | /
 *         3
 *         |
 *         4
 *         |
 *         5
 *
 * Output: [3, 4]
 * Note:
 *
 * According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
 * The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
 * */

package BFS.minimum_height_tree_310;

import java.util.*;

public class Solution {


    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if (n == 1) {
            //return new ArrayList<>(0);
            return Collections.singletonList(0);
        }
        List<Set<Integer>> adjList = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            adjList.add(new HashSet<>());
        }
        for (int[] edge : edges) {
            adjList.get(edge[0]).add(edge[1]);
            adjList.get(edge[1]).add(edge[0]);
        }
        List<Integer> leaves = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (adjList.get(i).size() == 1) {
                leaves.add(i);
            }
        }
        /**
         *
         * 最后一个简单而清晰的思路是：不断去掉叶子节点，每次去掉一层。去掉后又会产生新的叶子节点。
         *
         * 层层剥离后，最终剩下的1-2个节点就是解。
         *
         * 这样可行的原因就是，根节点一定是离所有叶子节点最远的那个节点。
         * */
        int count = n;
        while (count > 2) {
            count = count - leaves.size();
            List<Integer> newLeaves = new ArrayList<>();
            for (int i : leaves) {
                int j = adjList.get(i).iterator().next();
                adjList.get(j).remove(i);
                if (adjList.get(j).size() == 1) {
                    // 裁剪掉叶子之后,再更新leaves 数组,保存所有的叶子节点.
                    newLeaves.add(j);
                }
            }
            leaves = newLeaves;
        }
        return leaves;
    }
}
