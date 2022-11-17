/**
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given the below binary tree and sum = 22,
 *
 *       5
 *      / \
 *     4   8
 *    /   / \
 *   11  13  4
 *  /  \    / \
 * 7    2  5   1
 * Return:
 *
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
 *
 * */

package tree.path_sum_2_113;

import tree.TreeNode;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    private static List<List<Integer>> res = new ArrayList<>();

    public static List<List<Integer>> pathSum(TreeNode root, int sum) {
        if (null == root) {
            return res;
        }
        backTrace(root, new ArrayList<Integer>(), sum);
        return res;
    }
    private static void backTrace(TreeNode node, List<Integer> tmpList, int sum) {
        if(node == null ) {
            return;
        }
        if (isLeaf(node) && (sum - node.val == 0)) {
            tmpList.add(node.val);
            res.add(new ArrayList<>(tmpList));
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
    private static boolean isLeaf(TreeNode node) {
        if (node.left == null && node.right == null) {
            return true;
        } else {
            return false;
        }
    }
    public static void main(String[] arguments) {
        TreeNode node5 = new TreeNode(5);
        TreeNode node4 = new TreeNode(4);
        TreeNode node8 = new TreeNode(8);
        TreeNode node11 = new TreeNode(11);
        TreeNode node13 = new TreeNode(13);
        TreeNode node42 = new TreeNode(4);
        TreeNode node7 = new TreeNode(7);
        TreeNode node2 = new TreeNode(2);
        TreeNode node1 = new TreeNode(1);
        TreeNode node52 = new TreeNode(5);


        node5.left = node4;
        node5.right = node8;

        node4.left = node11;

        node8.left = node13;
        node8.right = node42;

        node11.left = node7;
        node11.right = node2;

        node42.left = node52;
        node42.right = node1;

        pathSum(node5, 22);
        for (List<Integer> item:
        res) {
            System.out.println("" + item);
        }
    }
}
