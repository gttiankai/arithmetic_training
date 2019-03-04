/**
 * Given a binary tree, return the level order traversal of its nodes' values.
 *
 * (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 *
 *
 *
 * */
package tree.binary_tree_level_Order_traversal_102;

import tree.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> list = new ArrayList<>();
        if( null == root) {
            return list;
        }
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);
        while (queue.size() != 0) {
            // 很聪明的做法，使用levelNumber变量就解决了这个问题。
            // 一定要记住
            int levelNumber = queue.size();
            List<Integer> subList = new ArrayList<>();
            for (int i = 0; i < levelNumber; i++) {
                if (queue.peek().left != null) {
                    queue.offer(queue.peek().left);
                }
                if (queue.peek().right != null) {
                    queue.offer(queue.peek().right);
                }
                subList.add(queue.poll().val);
            }
            list.add(subList);
        }
        return list;
    }
}
