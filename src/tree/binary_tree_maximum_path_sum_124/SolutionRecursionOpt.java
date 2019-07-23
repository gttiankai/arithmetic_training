package tree.binary_tree_maximum_path_sum_124;

import tree.TreeNode;

public class SolutionRecursionOpt {


    private int maxSum = Integer.MIN_VALUE;

    /**
     * Runtime: 1 ms, faster than 99.94% of Java online submissions for Binary Tree Maximum Path Sum.
     * Memory Usage: 41.4 MB, less than 18.39% of Java online submissions for Binary Tree Maximum Path Sum.
     *
     * 从实际的经验来看, 还是在遍历的开头处理*空节点*, 代码写起来比较简介
     *
     * */
    public int maxPathSum(TreeNode root) {

        pathSum(root);
        return maxSum;
    }

    private int pathSum(TreeNode node) {
        if (node == null) {
            return 0;
        }
        int leftPathSum = Math.max(pathSum(node.left), 0);

        int rightPathSum = Math.max(pathSum(node.right), 0);

        int currentPathSum = node.val + leftPathSum + rightPathSum;

        if (currentPathSum > maxSum) {
            maxSum = currentPathSum;
        }
        return node.val + Math.max(leftPathSum, rightPathSum);
    }
}
