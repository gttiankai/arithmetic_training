/**
 * You are given a binary tree in which each node contains an integer value.
 *
 * Find the number of paths that sum to a given value.
 *
 * The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent
 *
 * nodes to child nodes).
 *
 * The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
 *
 * Example:
 *
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 *
 *       10
 *      /  \
 *     5   -3
 *    / \    \
 *   3   2   11
 *  / \   \
 * 3  -2   1
 *
 * Return 3. The paths that sum to 8 are:
 *
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
 */

package tree.path_sum_3_437;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    private static List<List<Integer>> res = new ArrayList<>();
    public static int pathSum(TreeNode root, int sum) {
        if (null == root) {
            return 0;
        }
        backTrace(root, new ArrayList<>(),sum);
        if (root.left != null) {
            backTrace(root.left, new ArrayList<>(), sum);
        }
        if (root.right != null){
            backTrace(root.right, new ArrayList<>(), sum);
        }
        // 问题就出在这一行代码中.这个地方不能返回
        return res.size();
    }
    private static void backTrace(TreeNode node, List<Integer> tmpList, int sum) {
        if(node == null ) {
            return;
        }
        if ( sum - node.val == 0) {
            tmpList.add(node.val);
            res.add(new ArrayList<>(tmpList));
            return;
        }
        if (sum - node.val < 0) {
            return;
        }
        tmpList.add(node.val);
        if (node.left != null) {
            backTrace(node.left, tmpList, sum-node.val);
            tmpList.remove(tmpList.size()-1);
        }
        if (node.right != null) {
            backTrace(node.right, tmpList, sum-node.val);
            tmpList.remove(tmpList.size()-1);
        }
    }
    public static void main(String[] argument) {
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(4);
        TreeNode node5 = new TreeNode(5);

        node1.right = node2;
        node2.right = node3;
        node3.right = node4;
        node4.right = node5;

        System.out.printf(""+ pathSum(node1, 3));
    }
}
