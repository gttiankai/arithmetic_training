package tree.kth_smallest_element_in_a_bst_230;

import java.util.*;
import tree.TreeNode;

class Solution1 {

    /**
     * Runtime: 1 ms, faster than 48.82% of Java online submissions for Kth Smallest Element in a BST.
     * Memory Usage: 37.8 MB, less than 98.52% of Java online submissions for Kth Smallest Element in a BST.
     *
     * 使用中序遍历直接处理问题， 根据上面的显示，肯定还有办法进行优化，但是不清楚如何优化。
     * */
    public int kthSmallest(TreeNode root, int k) {

        List<Integer> list = new ArrayList<>();
        inOrder(root, list);
        return list.get(k-1);
    }

    private void inOrder(TreeNode root, List<Integer> list) {
    
        if (root == null) {
            return;
        }
        if (root.left != null) {
            inOrder(root.left, list);
        }
        list.add(root.val);
        if (root.right != null) {
            inOrder(root.right, list);
        }
    }
}