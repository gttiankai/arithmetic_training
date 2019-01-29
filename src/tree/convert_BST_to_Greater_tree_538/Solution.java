/**
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is
 *
 * changed to the original key plus sum of all keys greater than the original key in BST.
 *
 * Example:
 *
 * Input: The root of a Binary Search Tree like this:
 *               5
 *             /   \
 *            2     13
 *
 * Output: The root of a Greater Tree like this:
 *              18
 *             /   \
 *           20     13
 *
 *
 * */

package tree.convert_BST_to_Greater_tree_538;

import tree.TreeNode;

public class Solution {
    public TreeNode pre = new TreeNode(0);
    public TreeNode convertBST(TreeNode root) {
         TreeNode preNode = new TreeNode(0);
         convert(root);
         return root;

    }
    private void convert(TreeNode node) {
        if (null == node) {
            return;
        }
        if (node.right != null) {
            convert(node.right);
        }
        node.val = node.val + pre.val;
        pre = node;
        if (node.left != null) {
            convert(node.left);
            /**
             *
             * 这一行肯定要注释掉,因为已经通过访问顺序的原因,保证了pre的顺序,
             * 就没有必要在对pre进行赋值了.
             * pre = node.left;
             *
             * */

        }
        return;
    }
    public static void main(String[] arguments) {
        TreeNode node5= new TreeNode(5);
        TreeNode node2 = new TreeNode(2);
        TreeNode node13 = new TreeNode(13);

        node5.left = node2;
        node5.right = node13;
        Solution solution = new Solution();
        TreeNode res = solution.convertBST(node5);
        System.out.printf("" + res);
    }
}
