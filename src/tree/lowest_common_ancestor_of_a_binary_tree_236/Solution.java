/**
 *
 Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

 According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as

 the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]




 Example 1:

 Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 Output: 3
 Explanation: The LCA of nodes 5 and 1 is 3.
 Example 2:

 Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 Output: 5
 Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.


 Note:

 All of the nodes' values will be unique.
 p and q are different and both values will exist in the binary tree.
 *
 * */

package tree.lowest_common_ancestor_of_a_binary_tree_236;

import tree.TreeNode;

import javax.swing.plaf.nimbus.State;
import java.util.Stack;

public class Solution {
    /**
     * 寻找两个节点的共同祖先.
     * */
    private Stack<Integer> stack1 = new Stack<>();
    private Stack<Integer> stack2 = new Stack<>();
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (null == root || null == p || null == q) {
            return null;
        }
        preOrder(root, p, stack1);
        preOrder(root, q, stack2);
        if (stack1.size() == 0 || stack2.size() == 0) {
            return null;
        }
        while (!stack1.isEmpty()) {
            int temp = stack1.pop();
            if (stack2.contains(temp)) {
                return new TreeNode(temp);
            }
        }
        return null;
    }
    private boolean preOrder(TreeNode root, TreeNode node, Stack<Integer> stack) {
        if (root == null) {
            return false;
        }
        stack.push(root.val);
        if (root.val == node.val) {
            return true;
        }
        if (root.left != null) {
            if (preOrder(root.left, node, stack)){
                return true;
            }
        }
        if (root.right != null) {
            if (preOrder(root.right, node, stack)){
                return true;
            }
        }
        stack.pop();
        return false;
    }
    public static void main(String[] arguments) {

        TreeNode node0 = new TreeNode(0);
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(4);
        TreeNode node5 = new TreeNode(5);
        TreeNode node6 = new TreeNode(6);
        TreeNode node7 = new TreeNode(7);
        TreeNode node8 = new TreeNode(8);

        node3.left = node5;
        node3.right = node1;

        node5.left = node6;
        node5.right = node2;

        node2.left = node7;
        node2.right = node4;

        node1.left = node0;
        node1.right = node8;

        Solution solution = new Solution();
        solution.lowestCommonAncestor(node3, node5, node4);


    }


}
