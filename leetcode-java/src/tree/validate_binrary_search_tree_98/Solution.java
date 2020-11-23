/**
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * Example 1:
 *
 * Input:
 *     2
 *    / \
 *   1   3
 * Output: true
 * Example 2:
 *
 *     5
 *    / \
 *   1   4
 *      / \
 *     3   6
 * Output: false
 * Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
 *              is 5 but its right child's value is 4.
 * */

package tree.validate_binrary_search_tree_98;

import tree.TreeNode;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    /**
     * 确实使用递归的方式不容易判断是否是二叉查找树.
     *
     * 通过中序遍历的方式进行遍历,然后对得到的数据进行判断
     * space:   O(n)
     * time:
     *
     *
     * 二叉搜索树的定义:
     *  1. 若任意节点的左子树不空，则左子树上所有节点的值均小于它的根节点的值；
     *  2. 若任意节点的右子树不空，则右子树上所有节点的值均大于它的根节点的值；
     *  3. 任意节点的左、右子树也分别为二叉查找树；
     *  4. (*)没有键值相等的节点。
     * */
    public boolean isValidBST(TreeNode root) {
        if (null == root) {
            return true;
        }
        List<Integer> list = new ArrayList<>();
        inOrder(root, list);
        for (int i = 0; i < list.size()-1; i++) {
            if (list.get(i) >= list.get(i+1)) {
                return false;
            }
        }
        return true;

    }
    private void inOrder(TreeNode node, List<Integer> list) {
        if(node == null) {
            return;
        }
        inOrder(node.left, list);
        list.add(node.val);
        inOrder(node.right, list);
    }
}
