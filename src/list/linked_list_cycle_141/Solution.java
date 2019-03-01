/**
 * Given a linked list, determine if it has a cycle in it.
 * <p>
 * To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the
 * <p>
 * linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
 * <p>
 * <p>
 * <p>
 * Example 1:
 * <p>
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the second node.
 * <p>
 * <p>
 * Example 2:
 * <p>
 * Input: head = [1,2], pos = 0
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the first node.
 * <p>
 * <p>
 * Example 3:
 * <p>
 * Input: head = [1], pos = -1
 * Output: false
 * Explanation: There is no cycle in the linked list.
 * <p>
 * <p>
 * <p>
 * <p>
 * Follow up:
 * <p>
 * Can you solve it using O(1) (i.e. constant) memory?
 * <p>
 */
package list.linked_list_cycle_141;

import list.ListNode;

import java.util.HashSet;

public class Solution {

    // 这里面有一个固定的套路: 判断一个节点是否已经访问过,直接使用hash表
    public boolean hasCycleHash(ListNode head) {
        if (null == head || head.next == null) {
            return false;
        }
        HashSet<ListNode> set = new HashSet<>();
        ListNode tmp = head;
        while (tmp != null) {
            if (!set.contains(tmp)) {
                set.add(tmp);
                tmp = tmp.next;
            } else {
                return true;
            }
        }
        return false;
    }

    // 还有一种比较好的办法, 我命名为差速法,就是利用两个遍历节点的前进顺序不一样,然后最终判断两个如果相遇了,就说明这个链表是循环的.
    public boolean hasCycle(ListNode head) {
        if (null == head || head.next == null) {
            return false;
        }
        ListNode fast = head.next;
        ListNode slow = head;
        while (slow != fast) {
            if (fast == null || fast.next == null) {
                return false;
            }
            slow = slow.next;
            fast = fast.next.next;
        }
        return true;
    }
}
