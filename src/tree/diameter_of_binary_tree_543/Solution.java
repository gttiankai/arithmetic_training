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

public class
Solution {
    private int maxDiameter = 0;
    /**
     * 目前感觉这个算法,还是可以优化的,主要的优化点就是在preOrder这个算法中,
     * 原因是 up to down进行计算.
     * 要想办法变成直接处理down-to-up的方式,有效利用以前的计算结果.
     *
     * TODO: need tp op
     * */
    public int diameterOfBinaryTree(TreeNode root) {
        int max = 0;
        if (root == null) {
            return max;
        }
        preOrder(root);
        return maxDiameter;
    }
    public void preOrder(TreeNode node) {
        if (node == null) {
            return;
        }
        maxDiameter = Math.max(maxDiameter, diameter(node));
        if (node.left != null) {
            preOrder(node.left);
        }
        if (node.right != null) {
            preOrder(node.right);
        }
    }
    public int diameter(TreeNode node) {
        int diameter = 0;
        if (node == null) {
            return diameter;
        }
        int leftDepth = maxDepth(node.left);
        int rightDepth = maxDepth(node.right);
        /**
         * 求当前节点的时候,是不需要额外的+1的,这是因为根据定义,当前节点的值就是通过左右子树最大深度相加
         * diameter = leftDepth + rightDepth + 1;
         *
         * */
        diameter = leftDepth + rightDepth ;
        return diameter;
    }
    public int maxDepth(TreeNode node) {
        if (node == null) {
            return 0;
        }
        return Math.max(maxDepth(node.left) + 1, maxDepth(node.right) +1);
    }

    public static void main(String[] arguments) {
        Solution solution = new Solution();
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(4);
        TreeNode node5 = new TreeNode(5);
        node1.left = node2;
        node1.right = node3;

        node2.left = node4;
        node2.right = node5;
        System.out.printf("" + solution.diameterOfBinaryTree(node1));

    }
}
