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
    public int diameterOfBinaryTree(TreeNode root) {
        int max = 0;
        if (root == null) {
            return max;
        }
    }
    public int diameterOfNode(TreeNode node) {
        int diameter = 0;
        if (node == null) {
            return diameter;
        }
        return diameterOfNode(node.left) + diameterOfNode(node.right);
    }
    public int depth(TreeNode node) {
        int depth = 0;
        if (node == null) {
            return 0;
        }
        if (node.left != null) {
        }
    }
}
