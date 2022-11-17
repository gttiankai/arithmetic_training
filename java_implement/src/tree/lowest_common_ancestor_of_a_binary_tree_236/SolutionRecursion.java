package tree.lowest_common_ancestor_of_a_binary_tree_236;

import tree.TreeNode;

public class SolutionRecursion {
    private TreeNode ans = null;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        recursion(root, p, q);
        return ans;
    }


    private boolean recursion(TreeNode node, TreeNode p, TreeNode q) {

        if (node == null) {
            return false;
        }
        int left = recursion(node.left, p, q) ? 1 : 0;

        int right = recursion(node.right, p, q) ? 1 : 0;

        int mid = (node.val == p.val || node.val == q.val) ? 1 : 0;

        if (left + right + mid >= 2) {
            this.ans = node;
        }
        return left + right + mid > 0;
    }
}
