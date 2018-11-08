/**
 * Given a singly linked list, determine if it is a palindrome.
 * <p>
 * Example 1:
 * <p>
 * Input: 1->2
 * Output: false
 * Example 2:
 * <p>
 * Input: 1->2->2->1
 * Output: true
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 */

package PalindromeLinkedList_234;


import org.omg.PortableServer.LIFESPAN_POLICY_ID;

import java.util.List;

public class Solution {

    public static boolean isPalindrome(ListNode head) {
        /* *
         * 如何判断一个链表是否是回文的
         * time O(n)
         * space O(1)
         *
         * Solution 1：
         * 新建一个表，使用头插法，将表搞成逆序，然后遍历。
         * time :   O(n)
         * space:   O(n)
         *
         * Solution 2:
         * 参考了网上的办法，这个题目非常的有代表性：
         * 实现时间复杂度 O（n）是比较简单的，但是空间复杂度，是怎么保证为1的呢。
         * 主要实现的思想就是字符链表的原地的逆转，这个是不需要消耗新的空间。
         *
         * 简单来看就是将链表截断为两半，后面的一部分直接在原地进行逆转操作，不会消耗新的空间。
         * */
        if (head == null) {
            return false;
        }

        int length = 0;
        ListNode travel = head;
        while (travel != null) {
            length++;
            travel = travel.next;
        }
        int mid = length /2;
        ListNode reverseList = null;
        if (length %2 == 0) {
            // 偶数
            travel = head;
            int i = 0;
            while (i < mid) {
                i++;
                travel= travel.next;
            }
            reverseList = reverse(travel);

        } else {
            // 奇数
            travel = head;
            int i = 0;
            while (i < mid) {
                i++;
                travel= travel.next;
            }
            reverseList = reverse(travel.next);
        }

        while (reverseList != null) {
            if (head.val != reverseList.val) {
                return false;
            }else {
                head = head.next;
                reverseList = reverseList.next;
            }
        }
        return true;

    }

    private static ListNode reverse(ListNode head) {
        ListNode prev = null;
        while (head != null) {
            ListNode next = head.next;
            head.next = prev;
            prev =head;
            head = next;
        }
        return prev;
    }

    public static void main(String[] arguments) {
        ListNode header = new ListNode(1);
        ListNode second = new ListNode(1);
        ListNode third = new ListNode(2);
        ListNode fourth = new ListNode(1);
        header.next = second;
        second.next = third;
        third.next = fourth;
        fourth.next = null;
        System.out.println(String.valueOf(isPalindrome(header)));
    }
}
