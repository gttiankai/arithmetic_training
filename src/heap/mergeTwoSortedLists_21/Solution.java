/**
 *  Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes
 *
 *  of the first two lists.
 *
 *  Example:
 *
 *  Input: 1->2->4, 1->3->4
 *  Output: 1->1->2->3->4->4
 *
 * */

package heap.mergeTwoSortedLists_21;

public class Solution {

    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode guard = new ListNode(0);
        ListNode head = guard;
        while(l1 != null || l2 != null) {
            if (l1 == null) {
                guard.next = l2;
                break;
            }
            /*
            * 一开始出现问题，居然是忘记了 break
            * */
            if (l2 == null) {
                guard.next = l1;
                break;
            }
            if (l1.val <= l2.val) {
                guard.next = l1;
                guard = guard.next;
                l1 = l1.next;
            } else {
                guard.next = l2;
                guard = guard.next;
                l2 = l2.next;
            }
        }
        return head.next;
    }
    public static void main(String[] arguments) {

    }


}
