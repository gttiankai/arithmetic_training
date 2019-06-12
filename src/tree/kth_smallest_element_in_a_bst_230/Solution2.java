package tree.kth_smallest_element_in_a_bst_230;

import tree.TreeNode;

import java.util.Stack;

public class Solution2 {
    /**
     * 通过迭代的方式处理
     *
     * Runtime: 1 ms, faster than 48.82% of Java online submissions for Kth Smallest Element in a BST.
     * Memory Usage: 37.7 MB, less than 99.54% of Java online submissions for Kth Smallest Element in a BST.
     *
     * 然而并没有加快速度,虽然没有加快速度，但是这种递归的方案还是挺不错的
     * */
    public int kthSmallest(TreeNode root, int k) {

        Stack<TreeNode> stack = new Stack<TreeNode>();
        while (true) {
            while (root!= null) {
                stack.push(root);
                root = root.left;
            }
            root = stack.pop();
            k--;
            if (k == 0) {
                return root.val;
            }
            root = root.right;
        }

    }
}
