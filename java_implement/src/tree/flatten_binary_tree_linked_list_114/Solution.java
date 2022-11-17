/**
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example, given the following tree:
 *
 *     1
 *    / \
 *   2   5
 *  / \   \
 * 3   4   6
 * The flattened tree should look like:
 *
 * 1
 *  \
 *   2
 *    \
 *     3
 *      \
 *       4
 *        \
 *         5
 *          \
 *           6
 *
 * */

package tree.flatten_binary_tree_linked_list_114;

import tree.TreeNode;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    //
    private  List<Integer> list = new ArrayList<>();
    public void flattenMy(TreeNode  root) {
        if (root == null ) {
            return;
        }
        preOrder(root);
        TreeNode preNode = new TreeNode(0);
        preNode.left = null;

        TreeNode head = preNode;
        for (Integer item : list) {
            TreeNode node = new TreeNode(item);
            node.left = null;

            preNode.right = node;
            preNode = node;
        }
        // 这一步是个关键，为啥呢？ 因为Java代码是按值传递的，
        // root = head.right不能运行，需要进行一定的转换
        root.left = null;
        root.right = head.right.right;
    }
    private void preOrder(TreeNode node) {
        if (node == null) {
            return;
        }
        list.add(node.val);
        if (node.left != null) {
            preOrder(node.left);
        }
        if (node.right != null) {
            preOrder(node.right);
        }
    }

    /**
     * 看到一个绝了
     * 其实是使用了函数调用栈的原理，来处理的这个题目，很赞
     * */

    private TreeNode pre = null;
    public void flatten(TreeNode root) {
        if ( root == null) {
            return;
        }
        flatten(root.right);
        flatten(root.left);
        root.right = pre;
        root.left = null;
        pre = root;
    }

    public static void main(String[] arguments) {
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(4);
        TreeNode node5 = new TreeNode(5);
        TreeNode node6 = new TreeNode(6);
        node1.left = node2;
        node1.right = node5;
        node2.left = node3;
        node2.right = node4;
        node5.right = node6;
        Solution solution = new Solution();
        solution.flatten(node1);

    }
}
