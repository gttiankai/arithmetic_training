/**
 * Invert a binary tree.
 * <p>
 * Example:
 * <p>
 * Input:
 * <p>
 * 4
 * /   \
 * 2     7
 * / \   / \
 * 1 3  6   9
 * Output:
 * <p>
 * 4
 * /  \
 * 7    2
 * / \  / \
 * 9  6 3   1
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 * <p>
 * Google: 90% of our engineers use the software you wrote (Homebrew),
 * <p>
 * but you can’t invert a binary tree on a whiteboard so f*** off.
 */

package tree.invert_binary_tree_226;

import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    /*
     * 看来我也进不了 google了,第一次没有解决出来.问题出在什么地方?
     *
     * answer: 问题出在使用了函数调用,Java 中的所有的参数传递都是值传递,
     * 在函数体内部的操作,不会影响到外边,也就是 root.
     *
     * 从上到下进行处理的思路并没有错.
     * */

    public TreeNode invertTreeFailed(TreeNode root) {
        if (null == root) {
            return root;
        }
        // 从上到下的方式,好像不能工作啊.
        swap(root.left, root.right);
        invertTreeFailed(root.left);
        invertTreeFailed(root.right);
        return root;
    }

    private void swap(TreeNode node1, TreeNode node2) {
        TreeNode tmp = node1;
        node1 = node2;
        node2 = tmp;
    }

    /**
     * 不使用函数调用的方式,直接在函数内部进行处理,是可以成功的
     */

    public TreeNode invertTreeUpToDown(TreeNode root) {
        if (null == root) {
            return root;
        }
        // 从上到下的方式,好像不能工作啊.
        TreeNode tmp = root.left;
        root.left = root.right;
        root.right = tmp;
        invertTreeFailed(root.left);
        invertTreeFailed(root.right);
        return root;
    }

    public TreeNode invertTree(TreeNode root) {
        if (null == root) {
            return root;
        }
        // 从上到下的方式,好像不能工作啊.
        TreeNode left = invertTree(root.left);
        TreeNode right = invertTree(root.right);
        root.left = right;
        root.right = left;
        return root;
    }

    /**
     * 以上的方式都是使用递归的方式,下面要使用迭代的方式.说实话,目前我还不知道迭代和递归有什么区别?
     * <p>
     * answer: 昨晚这道题目终于明白了, 迭代就是使用循环的方式解决问题,递归就是使用调用函数的方式解决问题.
     * <p>
     * 由于函数调用会消耗CPU和内存, 迭代的方式一般都优于递归的方式,而且一般能用递归解决的问题,都可以使用迭代解决.
     */
    public TreeNode invertTreeIterate(TreeNode root) {
        if (null == root) {
            return root;
        }
        // ? 明天要看下书本, 这个地方 queue 是怎么回事? 为啥要用 LinkedList
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();
            TreeNode tmp = current.left;
            current.left = current.right;
            current.right = tmp;
            if (current.left != null) {
                queue.add(current.left);
            }
            if (current.right != null) {
                queue.add(current.right);
            }
        }
        return root;
    }


}
