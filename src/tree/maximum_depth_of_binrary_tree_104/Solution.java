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

package tree.maximum_depth_of_binrary_tree_104;

public class Solution {
    /**
     *  最直观的想法是使用回溯的方式,然后找出深度最大的路径
     *
     *  准确的说法是使用递归的方式,就可以直接获取到深度.
     *
     *  个人感觉求取树的深度可以后面的一个基础的功能.
     **/
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return Math.max(maxDepth(root.left)+1, maxDepth(root.right) + 1);
    }
}
