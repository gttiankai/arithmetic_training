package tree.lowest_common_ancestor_of_a_binary_searchTree_235;

import tree.TreeNode;

public class SolutionRecursion {

    /**
     * 执行用时 :11 ms, 在所有 Java 提交中击败了73.31%的用户
     * 内存消耗 :41 MB, 在所有 Java 提交中击败了11.28%的用户
     * 时间复杂度: 最坏:O(N) 平均下来O(log(N))
     * */
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        if (root == null) {
            return null;
        }
        if (p.val > root.val && q.val > root.val) {
            return lowestCommonAncestor(root.right, p, q);
        } else if (p.val < root.val && q.val < root.val) {
            return lowestCommonAncestor(root.left, p, q);
        } else {
            return root;
        }
    }
}
