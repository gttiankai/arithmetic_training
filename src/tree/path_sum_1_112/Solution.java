/**
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * <p>
 * such that adding up all the values along the path equals the given sum.
 * <p>
 * Note: A leaf is a node with no children.
 * <p>
 * Example:
 * <p>
 * Given the below binary tree and sum = 22,
 * <p>
 * 5
 * / \
 * 4   8
 * /   / \
 * 11  13  4
 * /  \      \
 * 7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */


package tree.path_sum_1_112;

import tree.TreeNode;

import java.util.ArrayList;
import java.util.Stack;

public class Solution {
    // 使用的是回溯法

    /**
     * 最终发现使用回溯法是没有办法进行处理的,还要想其他的办法
     */
    public boolean hasPathSumBackTrace(TreeNode root, int sum) {
        if (null == root) {
            return false;
        }
        ArrayList list = new ArrayList();
        return backStace(root, sum, list);
    }

    public boolean backStace(TreeNode root, int sum, ArrayList<Integer> list) {
        if (sum == 0) {
            return true;
        }
        while (root != null) {
            list.add(root.val);
            if (root.left != null) {
                backStace(root.left, sum - root.val, list);
            }
            if (root.right != null) {
                backStace(root.right, sum - root.val, list);
            }
            list.remove(root.val);
        }
        return false;
    }

    /**
     *
     */
    private static Stack<TreeNode> stack = new Stack<>();

    /**
     * 该方法能够解决全是正数的树, 但是一旦树中包含了负数, 则会出现问题.
     * 去掉 sum < 0的判断就可以了.
     * <p>
     * 最后解决了这个问题,
     */
    public static boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) {
            return false;
        }
        if (isLeaf(root)) {
            if (sum - root.val == 0) {
                return true;
            } else {
                return false;
            }
        }

        if (root.left != null) {
            if (hasPathSum(root.left, sum - root.val)) {
                return true;
            }
        }
        if (root.right != null) {
            if (hasPathSum(root.right, sum - root.val)) {
                return true;
            }
        }
        // WARNING
        // *这个是最后的一个返回的点, 很重要*,如果不能满足的话,最终跟你会回到这个点上来

        return false;
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

        node5.left = node4;
        node5.right = node8;

        node4.left = node11;

        node8.left = node13;
        node8.right = node42;

        node11.left = node7;
        node11.right = node2;

        node4.right = node1;

        TreeNode node_2 = new TreeNode(-2);
        TreeNode node_3 = new TreeNode(-3);
        node_2.right = node_3;

        //System.out.printf("" + hasPathSum(node5, 22));
        System.out.printf("" + hasPathSum(node_2, -5));


    }
}
