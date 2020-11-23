/*
  Given a non-empty binary tree, find the maximum path sum.

  For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

  Example 1:

  Input: [1,2,3]

   1
  / \
  2   3

  Output: 6
  Example 2:

  Input: [-10,9,20,null,null,15,7]

  -10
  / \
  9  20
    /  \
  15   7

  Output: 42


 */

package tree.binary_tree_maximum_path_sum_124;

import tree.TreeNode;

public class Solution {

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
            return root.val;
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
        if (leftPathSum > 0 ) {
            currentPathSum += leftPathSum;
        }
        if (rightPathSum > 0) {
            currentPathSum += rightPathSum;
        }
        if (currentPathSum > ans) {
            ans = currentPathSum;
        }
        return currentPathSum;
    }
}
