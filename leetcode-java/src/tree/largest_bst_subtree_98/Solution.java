/**
 * Given a binary tree, find the largest subtree which is a Binary Search Tree (BST),
 *
 * where largest means subtree with largest number of nodes in it.
 *
 * Note:
 * A subtree must include all of its descendants.
 *
 * Here's an example:
 *
 *     10
 *     / \
 *    5  15
 *   / \   \
 *  1   8   7
 * The Largest BST Subtree in this case is the highlighted one.
 * The return value is the subtree's size, which is 3.
 *
 * Hint:
 *
 * You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node
 *
 * of the tree, which will result in O(nlogn) time complexity.
 *
 * Follow up:
 * Can you figure out ways to solve it with O(n) time complexity?
 *
 *
 * */

package tree.largest_bst_subtree_98;

import tree.TreeNode;

public class Solution {

    /**
     * 这个算法确实改变了 TreeNode 的结构,
     * */
    public int largestBSTSubtree(TreeNode root){
        if (root == null) {
            return 0;
        }
        int ans = 0;
        DFS(root, ans);
        return ans;
    }
    private void DFS(TreeNode root, int ans) {
        if (root == null) {
            return;
        }


    }
    private boolean isBST(TreeNode root) {
        TreeNode left = root.left;
        TreeNode right = root.right;
        if (left == null && right == null) {

        }
        return false;
    }


    private int count(TreeNode node) {
        if (node == null) {
            return 0;
        }
        return count(node.left) + count(node.right) + 1;
    }
}
