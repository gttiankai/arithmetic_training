/**
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 *
 * such that adding up all the values along the path equals the given sum.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Given the below binary tree and sum = 22,
 *
 *       5
 *      / \
 *     4   8
 *    /   / \
 *   11  13  4
 *  /  \      \
 * 7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 *
 * */


package tree.path_sum_1_112;

import tree.TreeNode;

import java.util.ArrayList;

public class Solution {
    // 使用的是回溯法
    /**
     * 最终发现使用回溯法是没有办法进行处理的,还要想其他的办法
     *
     * */
    public boolean hasPathSum(TreeNode root, int sum) {
        if (null == root) {
            return false;
        }
        ArrayList list = new ArrayList();
        return backStace(root, sum, list);
    }

    public boolean backStace(TreeNode root, int sum, ArrayList<Integer> list) {
        if (sum == 0) {
            return true;
        }
        while (root != null) {
            list.add(root.val);
            if (root.left != null){
                backStace(root.left, sum-root.val, list);
            }
            if (root.right != null) {
                backStace(root.right, sum-root.val, list);
            }
            list.remove(root.val);
        }
        return false;
    }

}
