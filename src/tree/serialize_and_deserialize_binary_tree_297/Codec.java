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

import heap.sliding_window_maximum_239.Solution;
import tree.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

public class Codec {
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

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null) {
            return null;
        }
        String[] list = data.split(",");
        TreeNode head = new TreeNode(Integer.valueOf(list[0]));
        TreeNode pointer = head;
        for (int i = 0; i < list.length; i++) {
            TreeNode node;
            if (!list[1].equals("null")) {
                node = new TreeNode(Integer.valueOf(list[i]));
            }else {
                node = null;
            }

        }
        return null;
    }

    public static void main(String[] arguments) {
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(4);
        TreeNode node5 = new TreeNode(5);

        node1.left = node2;
        node1.right = node3;
        node3.left = node4;
        node3.right = node5;
        Codec codec = new Codec();
        String str  = codec.serialize(node1);
        codec.deserialize(str);
    }
}


// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
