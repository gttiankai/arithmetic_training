package tree.house_robber_3_337;

import tree.TreeNode;

import java.util.HashMap;

public class Solution2 {
    /**
     * 添加了 dp 记录中间值,然后提高运行速度
     * 4 ms, faster than 53.24%
     *
     *
     * */
    public int rot(TreeNode root) {
        return subRob(root, new HashMap<TreeNode, Integer>());
    }
    public int subRob(TreeNode root, HashMap<TreeNode, Integer> dp) {
        if(root == null) {
            return 0;
        }
        if (dp.containsKey(root)) {
            return dp.get(root);
        }
        int val = 0;
        if (root.left != null) {
            val += subRob(root.left.left, dp) + subRob(root.left.right, dp);
        }
        if (root.right != null) {
            val += subRob(root.right.left, dp)+ subRob(root.right.right, dp);
        }
        int maxValue =  Math.max(root.val + val, subRob(root.left, dp) + subRob(root.right, dp));
        dp.put(root, maxValue);
        return maxValue;
    }
}
