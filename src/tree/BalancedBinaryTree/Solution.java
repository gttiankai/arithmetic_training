/*
* Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
*
* **/

package tree.BalancedBinaryTree;


import org.omg.CORBA.MARSHAL;

public class Solution {

    /**
     * 首先判断当前节点是不是平衡的,然后判断自己的左右节点是不是平衡的
     * */
    public boolean isBalanced(TreeNode root) {
        if (null == root) {
            return true;
        }
        int left = depth(root.left);
        int right = depth(root.right);

        return Math.abs(left - right) <= 1 &&
                isBalanced(root.left) &&
                isBalanced(root.right);
    }
    public int depth(TreeNode root) {
        if (null == root) {
            return 0;
        }
        return Math.max(depth(root.left), depth(root.right)) + 1;
    }

    public boolean isBalancedPostOder(TreeNode root) {
        if (dfsHeight(root) == -1) {
            return false;
        } else {
            return true;
        }
    }

    public int dfsHeight(TreeNode root) {
        if (null == root) {
            return 0;
        }

        // 遍历左子树
        int left = dfsHeight(root.left);
        if(left == -1) {
            return -1;
        }
        // 遍历右子书
        int right = dfsHeight(root.right);

        if (right == -1){
            return -1;
        }

        // 查看根节点
        if (Math.abs(left - right) > 1) {
            return -1;
        }
        return Math.max(left, right) + 1;
    }




}
