package tree.subtree_of_another_tree_572;

import tree.TreeNode;

public class Solution1 {
    /**
     * 第一次尝试失败了,不好处理特殊情况.
     *
     * */
    public boolean isSubtree(TreeNode s, TreeNode t) {
        return subtree(s, t);
    }
    public boolean subtree(TreeNode s, TreeNode t){
        if (s == null) {
            return false;
        }
        /**
         * 第一次没有成功的原因: 这个此处没有处理好,此处非常巧妙的使用了一个递归调用的形式
         * */
        return (equals(s, t) || subtree(s.left, t) || subtree(s.right, t));
    }
    /**
     * 这个比较两棵树的方式比较好, 可以好好学习一下
     *
     * */
    public boolean equals(TreeNode node1, TreeNode node2) {
        if (node1 == null && node2 == null) {
            return true;
        }
        if (node1 == null || node2 == null) {
            return false;
        }
        return node1.val == node2.val && equals(node1.left, node2.left) &&
                equals(node1.right, node2.right);
    }

}
