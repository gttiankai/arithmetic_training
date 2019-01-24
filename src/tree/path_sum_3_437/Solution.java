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
 *
 *
 * [5,4,8,11,null,13,4,7,2,null,null,5,1]
 * 22
 */

package tree.path_sum_3_437;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    /**
     * 最终这个方案是可以的,但是由于输入的用例太多,造成 leetcode 的 Memory Limit Exceeded.
     * 这个方案还需要优化
     * */
    private static List<List<Integer>> res = new ArrayList<>();
    public static int pathSum(TreeNode root, int sum) {
        if (null == root) {
            return 0;
        }
        // 前序遍历

        travel(root, sum);
        // 问题就出在这一行代码中.这个地方不能返回
        return res.size();
    }
    private static void travel(TreeNode root, int sum) {
        System.out.println("" + root.val);
        backTrace(root, new ArrayList<>(),sum);
        if (root.left != null) {
            travel(root.left, sum);
        }
        if (root.right != null) {
            travel(root.right, sum);
        }
    }

    private static void backTrace(TreeNode node, List<Integer> tmpList, int sum) {
        if(node == null ) {
            return;
        }
        tmpList.add(node.val);
        if (sum - node.val == 0) {
            res.add(new ArrayList<>(tmpList));
            //return;
        }

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
//
//        TreeNode node5 = new TreeNode(5);
//        TreeNode node4 = new TreeNode(4);
//        TreeNode node8 = new TreeNode(8);
//        TreeNode node11 = new TreeNode(11);
//        TreeNode node13 = new TreeNode(13);
//        TreeNode node42 = new TreeNode(4);
//        TreeNode node7 = new TreeNode(7);
//        TreeNode node2 = new TreeNode(2);
//        TreeNode node52 = new TreeNode(5);
//        TreeNode node1 = new TreeNode(1);
//
//        node5.left = node4;
//        node5.right = node8;
//
//        node4.left = node11;
//
//        node11.left = node7;
//        node11.right = node2;
//
//        node8.left = node13;
//        node8.right = node42;
//
//        node42.left = node52;
//        node42.right = node1;
//
//        TreeNode node_2 = new TreeNode(-2);
//        TreeNode node_3 = new TreeNode(-3);
//        node_2.right = node_3;

        TreeNode node1 = new TreeNode(1);
        TreeNode node_2 = new TreeNode(-2);
        TreeNode node_3 = new TreeNode(-3);
        TreeNode node11 = new TreeNode(1);
        TreeNode node3 = new TreeNode(3);
        TreeNode node_22 = new TreeNode(-2);
        TreeNode node_1 = new TreeNode(-1);

        node1.left = node_2;
        node1.right = node_3;

        node_2.left = node11;
        node_2.right = node3;

        node11.left = node_1;

        node_3.left = node_22;

        System.out.printf(""+ pathSum(node1, -1));
    }
}
