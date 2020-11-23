/**
 * Reverse a singly linked list.
 * <p>
 * Example:
 * <p>
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 */

package linked_list.reverse_linked_list_206;

public class Solution {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Reverse Linked List.
     * congratulations
     * 使用迭代法
     */

    public ListNode reverseList(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode res = null;
        ListNode pre = head;
        ListNode p = head.next;
        while (pre != null) {
            pre.next = res;
            res = pre;
            pre = p;
            if (pre == null) {
                break;
            }
            p = p.next;
        }
        return res;
    }

    /**
     * 这个题目想起来还是有点难想的
     *
     * 这个就要使用递归法了.
     *
     * 通过这个题目发现,递归并不一定比迭代从思路上来看来的简单.这个题目明天递归的思路更难想一点.
     *
     * 但是递归和迭代,还是想伴随而生的.
     */
    public ListNode reverseListReverse(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode p = reverseListReverse(head.next);
        /** 下面这个返回之后的中间状态
         * n1->n2->n3... ->n(m-2)->n(m-1) <-n(m)
         *                           \
         *                            >null
         *                  head             p
         *
         *
         */
        head.next.next = head;
        head.next = null;
        return p;
        /** 下面这个返回之后的中间状态
         * n1->n2->n3... ->n(m-2)<-n(m-1) <-n(m)
         *                   \
         *                    >null
         *                  head             p
         *
         *
         */

    }
}
