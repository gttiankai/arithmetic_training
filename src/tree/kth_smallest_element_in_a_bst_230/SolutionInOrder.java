package tree.kth_smallest_element_in_a_bst_230;

import tree.TreeNode;

public class SolutionInOrder {
    /*
      Runtime: 0 ms, faster than 100.00% of Java online submissions for Kth Smallest Element in a BST.
      Memory Usage: 37.9 MB, less than 95.92% of Java online submissions for Kth
      Smallest Element in a BST.

      其实是中序遍历的优化方案,不用整个中序遍历,只需要遍历需要的时间
      最好的情况下的时间复杂度: O(k)
     */
    private int index = 0;
    public int kthSmallest(TreeNode root, int k) {

        if (root == null) {
            new Exception("root is null");
            return -1;
        }
        int[] ans = new int[k];
        inOrder(root, ans, k);
        return ans[k-1];
    }

    private void inOrder(TreeNode node, int[] ans, int k) {
        if (node.left != null) {
            inOrder(node.left, ans, k);
        }
        if (index == k) {
            return;
        }
        ans[index++] = node.val;
        if (node.right != null) {
            inOrder(node.right, ans, k);
        }
    }
}
