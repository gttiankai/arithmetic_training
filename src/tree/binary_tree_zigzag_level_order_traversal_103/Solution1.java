import java.util.*;

class Solution1 {
    
    List<List<Integer>> result = new ArrayList<List<Integer>>();

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        helper(root, 0);
        return result;
    }

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