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
import java.util.*;

public class Solution {
    /**
     * 思路其实很简单:
     *  1. 分别将两个节点在树中进行查找,得到两个包含经过节点的栈(stack)
     *  2. 找出这两个栈中最晚的节点
     * */

    public TreeNode lowestCommonAncestorSearch(TreeNode root, TreeNode p, TreeNode q) {
        if (null == root || null == p || null == q) {
            return null;
        }
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();
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

    /**
     * 这个方法使用了递归的方式,只需要遍历一般树就可以了.
     *
     * 这个方法,其实使用了标记路径的方式,但是由于使用的方法很巧妙,
     * 所以不需要使用一个数组进行表示.
     * 所以不需要使用一个数组进行表示.
     * */
    private TreeNode ans = null;
    public boolean recurseTree(TreeNode currentNode, TreeNode p, TreeNode q) {
        if (currentNode == null) {
            return false;
        }
        int left = 0, right = 0, mid = 0;
        if (recurseTree(currentNode.left, p, q)){
            left = 1;
        }
        if (recurseTree(currentNode.right, p, q)) {
            right = 1;
        }
        if (currentNode.val == p.val || currentNode.val == q.val) {
            mid = 1;
        }
        if (left + right + mid >= 2) {
            ans = currentNode;
        }
        return left + right + mid > 0;
    }
    public TreeNode lowestCommonAncestorRecurse(TreeNode root, TreeNode p, TreeNode q){
        recurseTree(root, p, q);
        return ans;
    }

    /**
     *  父指针的方式,我也想到了,但是不知道怎么做,当时想的办法是改变 TreeNode 的结构,这显然是不行的.
     *  总结下来就是使用了map 将父子关系存储起来.
     **/
    public TreeNode lowestCommonAncestorFatherPointer(TreeNode root, TreeNode p, TreeNode q) {

        // Stack for tree traversal
        Deque<TreeNode> stack = new ArrayDeque<>();

        // HashMap for parent pointers
        // 这个父进程,其实是将所有的父子关系,通过 map 的方式保存下来.
        Map<TreeNode, TreeNode> parent = new HashMap<>();

        parent.put(root, null);
        stack.push(root);

        // Iterate until we find both the nodes p and q
        // 这个条件设置的很好, 只要遍历到 p 和 q 都访问到了,就可以直接退出了,
        // 并且其中的父子关系都保存下来了.
        while (!parent.containsKey(p) || !parent.containsKey(q)) {
            TreeNode node = stack.pop();

            // While traversing the tree, keep saving the parent pointers.
            if (node.left != null) {
                parent.put(node.left, node);
                stack.push(node.left);
            }
            if (node.right != null) {
                parent.put(node.right, node);
                stack.push(node.right);
            }
        }
        // Ancestors set() for node p.
        Set<TreeNode> ancestors = new HashSet<>();

        // Process all ancestors for node p using parent pointers.
        while (p != null) {
            ancestors.add(p);
            p = parent.get(p);
        }

        // The first ancestor of q which appears in
        // p's ancestor set() is their lowest common ancestor.
        // 一旦存在第一个,这个就是 lowest common ancestor
        while (!ancestors.contains(q)) {
            q = parent.get(q);
        }
        return q;

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
        solution.lowestCommonAncestorFatherPointer(node3, node5, node4);


    }


}
