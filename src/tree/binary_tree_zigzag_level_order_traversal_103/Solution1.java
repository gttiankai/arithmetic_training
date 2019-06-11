package tree.binary_tree_zigzag_level_order_traversal_103;

import java.util.*;
import tree.TreeNode;

class Solution1 {
    List<List<Integer>> result = new ArrayList<List<Integer>>();

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        helper(root, 0);
        return result;
    }

    // 这种方案之所以比我的方案快的原因是节点只需要读取一次，而我的方案需要首先读取到队列
    // 然后从队列中在进行读取，相当于每个元素，读取了两遍
    public void helper(TreeNode root, int level) {
        if (root == null)
            return;
        if (result.size() < level + 1) {
            result.add(new LinkedList<Integer>());
        }
        if (level % 2 == 1) {
            ((LinkedList) result.get(level)).addFirst(root.val);
        } else {
            ((LinkedList) result.get(level)).addLast(root.val);
        }
        helper(root.left, level + 1);
        helper(root.right, level + 1);
    }
}