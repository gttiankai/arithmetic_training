/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * <p>
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * <p>
 * 1
 * / \
 * 2   2
 * / \ / \
 * 3  4 4  3
 * But the following [1,2,2,null,3,null,3] is not:
 * 1
 * / \
 * 2   2
 * \   \
 * 3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 * unit test: [1,2,2,null,3,null,3]
 *
 * units test2: 遇到特例了,中序遍历解决不了问题.
 *
 * [1,2,3,3,null,2,null]
 */

package tree.symmetric_tree_101;

import java.util.ArrayList;

public class Solution {
    static ArrayList<Integer> arrayList = new ArrayList<Integer>();

    public static boolean isSymmetric(TreeNode root) {
        if (null == root) {
            return true;
        }
        inOrder(root);
        if (arrayList.size() == 0) {
            return true;
        }

        Object[] array = arrayList .toArray();
        // 镜像树的个数肯定是奇数的
        if (array.length % 2 == 0) {
            return false;
        }
        for (int i = 0; i < array.length / 2; i++) {
            if (array[i] != array[array.length - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    public static void inOrder(TreeNode root) {
        if (root == null) {
            return;
        }
        if (root.left != null) {
            inOrder(root.left);
        }
        arrayList.add(root.val);
        if (root.right != null) {
            inOrder(root.right);
        }
    }
    public static void main(String[] arguments) {
        //[1,2,2,null,3,null,3]
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(2);
        TreeNode node4 = new TreeNode(3);
        TreeNode node5 = new TreeNode(3);
        node1.left = node2;
        node1.right = node3;
        node2.right = node4;
        node3.right = node5;
        System.out.printf("" + isSymmetric(node1));
    }
}
