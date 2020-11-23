/**
 * Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a
 *
 * binary tree is the length of the longest path between any two nodes in a tree. This path may or may
 *
 * not pass through the root.
 *
 * Example:
 * Given a binary tree
 *           1
 *          / \
 *         2   3
 *        / \
 *       4   5
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 *
 *
 * */

package tree.diameter_of_binary_tree_543;

import tree.TreeNode;

public class Solution {
    public int max = 0;
    /**
     * 直接将问题分解,然后就可以解决这个问题.
     * 一开始解决不了的原因是混淆了diameter和depth的区别, 没有分的特别清楚.
     *
     * */
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) {
            return max;
        }
        preOrder(root);
        return max;
    }
    public void preOrder(TreeNode root) {
        if (root == null) {
            return ;
        }
        int diameter = diameterOfNode(root);
        if (diameter > max) {
            max = diameter;
        }
        preOrder(root.left);
        preOrder(root.right);
    }

    public int diameterOfNode(TreeNode node) {
        int diameter = 0;
        if (node == null) {
            return diameter;
        }
        return depth(node.left) + depth(node.right);
    }
    public int depth(TreeNode node) {
        if (node == null) {
            return 0;
        }
        return Math.max(depth(node.left), depth(node.right)) + 1;
    }
}
