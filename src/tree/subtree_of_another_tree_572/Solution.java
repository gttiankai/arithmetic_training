/**
 * Given two non-empty binary trees s and t, check whether tree t has exactly the
 *
 * same structure and node values with a subtree of s. A subtree of s is a tree
 *
 * consists of a node in s and all of this node's descendants. The tree s could also
 *
 * be considered as a subtree of itself.
 *
 * Example 1:
 * Given tree s:
 *
 *      3
 *     / \
 *    4   5
 *   / \
 *  1   2
 * Given tree t:
 *    4
 *   / \
 *  1   2
 * Return true, because t has the same structure and node values with a subtree of s.
 *
 * Example 2:
 * Given tree s:
 *
 *      3
 *     / \
 *    4   5
 *   / \
 *  1   2
 *     /
 *    0
 * Given tree t:
 *    4
 *   / \
 *  1   2
 * Return false.
 *
 * Note: tree s 是它本身的 substree
 *
 * */
package tree.subtree_of_another_tree_572;

import tree.TreeNode;

import java.util.HashSet;

public class Solution {
    /**
     * 第一次尝试失败了,不好处理特殊情况.
     *
     * */
    public boolean isSubtreeFailed(TreeNode s, TreeNode t) {
        // 由于题目中已经设定了 s 和 t 是非空的,所以不需要再进行 check
        if (s == null) {
            return true;
        }
        if (isSame(s, t)) {
            return (isSubtreeFailed(s.left, t.left) && isSubtreeFailed(s.right, t.right));
        }
        return false;

    }
//    public void preOrder(TreeNode s, TreeNode t) {
//        if (s == null) {
//            return;
//        }
//    }
    /**
     * s 和 t 节点相同,判断是否合法
     * */
    public boolean subtree(TreeNode s, TreeNode t){
        return false;
    }

    public boolean isSame(TreeNode node1, TreeNode node2) {
        return node1.val == node2.val;
    }

    /**
     * 感觉这个题目最重要的地方是在先序遍历的过程中,将返回值添加#, 并且
     * 最后通过子序列的方式进行判断,很好的解决了这个问题
     *
     * // TODO:
     * */
    HashSet< String > trees = new HashSet <>();

    public boolean isSubtree(TreeNode s, TreeNode t) {
        String tree1 = preOrder(s, true);
        String tree2 = preOrder(t, true);
        return tree1.indexOf(tree2) >= 0;
    }
    public String preOrder(TreeNode t, boolean left) {
        if (t == null) {
            if (left){
                return "lnull";
            } else {
                return "rnull";
            }
        }
        return "#"+t.val + " " +preOrder(t.left, true)+" " +
                preOrder(t.right, false);
    }
}
