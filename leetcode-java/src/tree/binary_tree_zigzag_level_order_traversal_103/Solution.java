/**
 Given a binary tree, return the zigzag level order traversal of its nodes' values. 
 
 (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
 * 
 */
package tree.binary_tree_zigzag_level_order_traversal_103;
import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.List;

import tree.TreeNode;

class Solution {
    /**
     * Runtime: 1 ms, faster than 77.43% of Java online submissions for Binary Tree Zigzag Level Order Traversal.
     * Memory Usage: 36.4 MB, less than 99.96% of Java online submissions for Binary Tree Zigzag Level Order Traversal.
     * 
     * TODO: 思考一下还有什么地方可以进行优化
     */
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if (root == null) {
            return new LinkedList<>();
        }
        Deque<TreeNode> queue = new LinkedList<>();
        queue.addLast(root);
        List<List<Integer>> ans = new ArrayList<>();
        boolean fifo = true;
        while(queue.size() > 0) {
            List<Integer> tmpList = new ArrayList<>();
            if (fifo) {
                // left to right
                int levelNumber = queue.size();
                
                for(int i = 0; i < levelNumber; i++) {
                    TreeNode guard = queue.getFirst();
                    if (guard.left != null) {
                        queue.addLast(guard.left);
                    }
                    if (guard.right != null) {
                        queue.addLast(guard.right);
                    }
                    tmpList.add(guard.val);
                    queue.removeFirst();
                }
                
                fifo = false;
            } else {
                // right to left
                int levelNumber = queue.size();
                for(int i = 0; i < levelNumber; i++){
                    TreeNode guard = queue.getLast();

                    if (guard.right != null) {
                        queue.addFirst(guard.right);
                    }
                    if (guard.left != null) {
                        queue.addFirst(guard.left);
                    }
                    tmpList.add(guard.val);
                    queue.removeLast();
                }
                fifo = true;
            }
            ans.add(tmpList);
            
        }
        return ans;
    }
}