package tree.populating_next_right_pointers_in_each_node_116;

public class Solution1 {
    /**
     * 这个方法是非常好的，还是要多看看
     * 
     * */
    public Node connect(Node root) {
        if (root == null) {
            return root;
        }
        Node level_start = root;
        while (level_start != null) {
            //TODO: need more resarch
            Node cur = level_start;
            // cur 当处于每一行的最后一个元素时,这个判断就会起作用了
            while (cur != null) {
                if (cur.left != null) {
                    cur.left.next = cur.right;
                }
                if (cur.right != null && cur.next != null) {
                    cur.right.next = cur.next.left;
                }
                // 这个地方是很好的位置
                cur = cur.next;
            }
            // 下一行的起点
            level_start = level_start.left;
        }
        return root;
    }
}
