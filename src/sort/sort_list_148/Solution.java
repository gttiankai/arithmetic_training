/**
 * Sort a linked list in O(n log n) time using constant space complexity.
 *
 * Example 1:
 *
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * Example 2:
 *
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
 *
 * 总结下来就是使用复杂度为 O(n log n)的时间复杂度的算法对链表进行排序.
 * 有两种排序算法: 快速排序和堆排序.
 * 居然还有一个归并排序,这个排序算法有印象,但是好久没有复习了,基本上忘记了.
 * */
package sort.sort_list_148;

import jdk.nashorn.internal.objects.NativeUint8Array;
import sort.ListNode;

public class Solution {
    /**
     * 归并排序的 top-down 算法
     * 常规的步骤:
     * 1. 分段
     * 2. 排序(包含递归)
     * 3. 合并
     * */
    public ListNode sortListTop2Down(ListNode head) {
        /**
         * 刚开始做的时候,第一行少了一个判断条件,
         * 一定要加上 head.next == null 要返回,
         * 如果没有这个条件,就是死锁,因为最后的递归返回的临界值是只有一个节点的链表进行排序.
         * */
        if (head == null || head.next == null) {
            return head;
        }
        ListNode fast, slow;

        // 这种 slow 和 fast 起始位置相等的做法,后面不利于分段.
//        slow = head;
//        fast = head;
//        while (fast != null) {
//            if (fast.next != null) {
//                fast = fast.next.next;
//            } else {
//                break;
//            }
//            slow = slow.next;
//        }
        slow = head;
        fast = head.next;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        ListNode mid = slow.next;
        slow.next = null;

        /**
         * sort list
         * */
        ListNode sortL1 = sortListTop2Down(head);
        ListNode sortL2 = sortListTop2Down(mid);
        return merge(sortL1, sortL2);
    }
    private ListNode merge(ListNode l1, ListNode l2){
        // 守卫节点
        ListNode ans = new ListNode(0);
        ListNode guard = ans;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                ans.next = l1;
                l1 = l1.next;
                ans = ans.next;
            } else {
                ans.next = l2;
                l2 = l2.next;
                ans = ans.next;
            }
        }
        if (l1 != null) {
            ans.next = l1;
        }
        if (l2 != null) {
            ans.next = l2;
        }
        return guard.next;
    }
    /**
     *  归并排序的第二种做法,从底向上进行排序
     *  这种方式增加了算法的设计难度,但是节省了空间复杂度,不需要进行递归的操作.
     *  时间复杂度是 O(nlog^n)
     * */
    public ListNode sortListBottom2Up(ListNode head) {
        if (null == head || head.next == null) {
            return head;
        }
        int n = 0;
        ListNode current = head;
        while (current!= null) {
            n++;
            current = current.next;
        }
        ListNode guard = new ListNode(0);
        guard.next = head;
        ListNode left , right, tail;
        for (int step = 1; step <= n; step<<=1) {
            current = guard.next;
            tail = guard;
            while (current != null) {
                left = current;
                right = split(left, step);
                current = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        return guard.next;
    }
    private ListNode split(ListNode head, int n) {
        /**
         * i的起始地址肯定是从1开始的.不能从0开始
         * */
        for (int i = 1; head != null && i < n; i++) {
            head = head.next;
        }
        if (head == null) {
            return null;
        }
        ListNode second = head.next;
        head.next = null;
        return second;
    }
    private ListNode merge(ListNode l1, ListNode l2, ListNode head) {
        ListNode current = head;
        while (l1 != null && l2 != null) {
            if (l1.val > l2.val) {
                current.next = l2;
                current = l2;
                l2 = l2.next;
            } else {
                current.next = l1;
                current = l1;
                l1 = l1.next;
            }
        }
        current.next = (l1 != null ? l1 : l2);
        while (current.next!= null) {
            current = current.next;
        }
        return current;
    }

    public static void main(String[] arguments) {
        // [-1,5,3,4,0]
        ListNode l_1 = new ListNode(-1);
        ListNode l5 = new ListNode(5);
        ListNode l3 = new ListNode(3);
        ListNode l4 = new ListNode(4);
        ListNode l0 = new ListNode(0);
        l_1.next = l5;
        l5.next = l3;
        l3.next = l4;
        l4.next = l0;
        Solution solution = new Solution();
        solution.sortListBottom2Up(l_1);

    }

}
