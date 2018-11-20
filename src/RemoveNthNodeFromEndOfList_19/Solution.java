/**
 * Given a linked list, remove the n-th node from the end of list and return its head.
 * <p>
 * Example:
 * <p>
 * Given linked list: 1->2->3->4->5, and n = 2.
 * <p>
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * <p>
 * Given n will always be valid.
 * <p>
 * Follow up:
 * <p>
 * Could you do this in one pass?
 */


package RemoveNthNodeFromEndOfList_19;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    // 这种方式失败了
    public ListNode removeNthFromEndFailed(ListNode head, int n) {
        if (null == head){
            return null;
        }
        if ( 0 == n) {
            return head;
        }
        int lenght = 0;
        ListNode pointer = head;
        while (pointer != null) {
            lenght++;
            pointer = pointer.next;
        }
        int need = lenght - n;
        if (0 == need && lenght == 1) {
            return null;
        }
        int count = 0;
        pointer = head.next;
        ListNode prePointer = null;
        while (pointer != null) {
            if (count == need) {
                prePointer.next = pointer.next;
                break;
            } else {
                prePointer = pointer;
                pointer = pointer.next;
                count ++;
            }
        }
        return head;
    }

    /**
     * slow pointer and faster pointer
     *
     * unit test: [1] 1
     * */
    public static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode guard = new ListNode(0);

        ListNode slow = guard;
        ListNode faster = guard;
        guard.next = head;

        /*
        * 找个循环的条件一定要满足，这就是为啥，程序做不出来的原因
        * */
        for (int i = 0; i <= n  ; i++) {
            faster = faster.next;
        }

        while (faster != null) {
            slow = slow.next;
            faster = faster.next;
        }
        slow.next = slow.next.next;
        return guard.next;

    }

    public static void main(String[] arguments) {
        ListNode header = new ListNode(1);
        header.next = null;
        System.out.println(removeNthFromEnd(header, 1));
    }
}
