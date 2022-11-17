/**
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be
 *
 * stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in
 *
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your
 *
 * serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized
 *
 * to a string and this string can be deserialized to the original tree structure.
 *
 * Example:
 *
 * You may serialize the following tree:
 *
 *     1
 *    / \
 *   2   3
 *      / \
 *     4   5
 *
 * as "[1,2,3,null,null,4,5]"
 * Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need
 *
 * to follow this format, so please be creative and come up with different approaches yourself.
 *
 * Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms
 *
 * should be stateless.
 *
 * */

package tree.serialize_and_deserialize_binary_tree_297;

import tree.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

public class
Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) {
            return null;
        }
        StringBuilder result = new StringBuilder();
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);
        while (queue.size() != 0) {
            TreeNode node = queue.poll();
            if (node == null) {
                result.append("null,");
            }else {
                result.append(node.val+",");
                queue.offer(node.left);
                queue.offer(node.right);
            }
        }
        System.out.printf("" + result.toString());
        return result.toString();
    }


    /**
     * 参考网上的算法
     * */
    public TreeNode deserialize(String data){
        if (data == null) {
            return null;
        }
        Queue<TreeNode> queue = new LinkedList<>();

        String[] list = data.split(",");
        TreeNode root = new TreeNode(Integer.valueOf(list[0]));
        queue.offer(root);

        for (int i = 1; i < list.length; i++) {
            TreeNode parent = queue.poll();
            // 当时是卡在了这个地方，需要注意一下。
            // 这种方式非常值得记住，用于其他的题目
            if(!list[i].equals("null")) {
                TreeNode left = new TreeNode(Integer.valueOf(list[i]));
                parent.left = left;
                queue.offer(left);
            }
            if (!list[++i].equals("null")) {
                TreeNode right = new TreeNode(Integer.valueOf(list[i]));
                parent.right = right;
                queue.offer(right);
            }
        }
        return root;
    }

    // Decodes your encoded data to tree.
    // 目前这种办法支队完全二叉树有效，对其他的情会有问题。
    public TreeNode deserializeFailed(String data) {
        if (data == null) {
            return null;
        }
        String[] list = data.split(",");
        return createBinaryTree(list, 0);
    }
    private TreeNode createBinaryTree(String[] list, int index) {
        TreeNode node = null;
        if (index < list.length) {
            if (list[index].equals("null")) {
                node = null;
            } else {
                int value = Integer.valueOf(list[index]);
                node = new TreeNode(value);
                node.left = createBinaryTree(list, 2*index +1);
                node.right = createBinaryTree(list, 2*index +2);
            }
        }
        return node;
    }



    public static void main(String[] arguments) {
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(4);
        TreeNode node5 = new TreeNode(5);
        TreeNode node31 = new TreeNode(3);
        TreeNode node21 = new TreeNode(2);

//        node5.left = node2;
//        node5.right = node3;
//        node3.left = node21;
//        node3.right = node4;
//        node21.left = node31;
//        node21.right = node1;
//

        TreeNode root = node1;
        node1.left = node2;
        node1.right = node3;
        node3.left = node4;
        node3.right = node5;

        Codec codec = new Codec();
        String str  = codec.serialize(root);
        TreeNode node = codec.deserialize(str);
        System.out.printf("haha");
    }
}


// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
