package tree.binary_tree_maximum_path_sum_124;

import tree.TreeNode;

public class SolutionRecursion {

    private int ans = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        pathSum(root);
        return ans;

    }

    private int pathSum(TreeNode root){
        if (root.left == null && root.right == null) {
           // FIXME: 返回之前要和 ans 进行比较,然后更新 ans;
            if (root.val > ans) {
                ans = root.val;
            }
            // FIXME: 此处一定要和0进行比较,代表,如果 root.val < 0 , 我们可以选
            // 择不加上这个点
            return Math.max(root.val, 0);
        }
        int leftPathSum = 0;
        int rightPathSum = 0;
        int currentPathSum = root.val;
        if (root.left != null) {
            leftPathSum = pathSum(root.left);
        }
        if (root.right != null) {
            rightPathSum = pathSum(root.right);
        }
        // FIXME: 下面的代码是从 Solution.java 的代码中修改来的

        if (leftPathSum > 0 ) {
            currentPathSum += leftPathSum;
        }
        if (rightPathSum > 0) {
            currentPathSum += rightPathSum;
        }
        if (currentPathSum > ans) {
            ans = currentPathSum;
        }

        // XXX:  返回的不能是 currentPathSum,因为题目要求的是两个节点的 path,当
        // 前的节点只能包含一边
        return root.val + Math.max(leftPathSum, rightPathSum);
    }
}
