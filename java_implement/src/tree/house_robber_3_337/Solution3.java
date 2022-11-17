package tree.house_robber_3_337;

import tree.TreeNode;

import java.util.HashMap;

public class Solution3 {
    /**
     * 添加了 dp 记录中间值,然后提高运行速度
     * Runtime: 0 ms, faster than 100.00%
     * 最后这个方法很牛逼,比上一个方法比较好的地方,是一次遍历,将两种情况都计算出来了,
     * 递归调用的次数明显变少了
     *
     * */
    public int rot(TreeNode root) {
        int[] ans =  subRob(root);
        return Math.max(ans[0], ans[1]);
    }
    public int[] subRob(TreeNode root) {
        if (root == null) {
            return new int[2];
        }
        int[] ans = new int[2];
        int[] left = subRob(root.left);
        int[] right = subRob(root.right);
        ans[0] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        ans[1] = root.val + left[0] + right[0];
        return ans;
    }
}
