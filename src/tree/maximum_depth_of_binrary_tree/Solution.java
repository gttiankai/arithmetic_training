/**
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node
 *
 * down to the farthest leaf node.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given binary tree [3,9,20,null,null,15,7],
 *
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its depth = 3.
 * */

package tree.maximum_depth_of_binrary_tree;

public class Solution {
    /**
     *  最直观的想法是使用回溯的方式,然后找出深度最大的路径
     **/
    public int maxDepth(TreeNode root) {

    }
    public int backTrace(TreeNode node) {
        if (node == null) {
            return 0;
        }
    }
}
