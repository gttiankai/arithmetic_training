package tree.house_robber_3_337;

import tree.TreeNode;

import java.util.HashMap;

public class Solution1 {
    /**
     * 使用 dp 的方式,注意保存计算的中间结果
     *
     *
     *
     * */
    public int robSlow(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int val = 0;
        if (root.left != null) {
            val += robSlow(root.left.left) + robSlow(root.left.right);
        }
        if (root.right != null) {
            val += robSlow(root.right.left)+ robSlow(root.right.right);
        }
        return Math.max(root.val + val, robSlow(root.left) + robSlow(root.right));
    }

}
