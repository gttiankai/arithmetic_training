/***
 *
 * 给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
 *
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 *
 * 示例：
 *
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 *
 * Definition for singly-linked list.
 *  public class ListNode {
 *       int val;
 *       ListNode next;
 *       ListNode(int x) { val = x; }
 *  }
 * unit test: {(1), (9 -> 9)} {null, (1 -> 2)}
 *
 *
 * **/

package add_two_number_2;

import org.omg.PortableServer.LIFESPAN_POLICY_ID;

import java.util.List;

public class Solution {

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null && l2 == null) {
            throw new IllegalArgumentException("the arguments is wrong");
        }
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }
        int carryFlag = 0;
        ListNode result = null;
        ListNode pointer = null;
        boolean isFirstNode = true;
        do {
            int sum = l1.val + l2.val + carryFlag;
            if (sum > 9) {
                carryFlag = 1;
                ListNode item = new ListNode(sum - 10);
                item.next = null;
                if (isFirstNode) {
                    result = item;
                    pointer = item;
                    isFirstNode = false;
                } else {
                    pointer.next = item;
                    pointer = item;
                }
            } else {
                carryFlag = 0;
                ListNode item = new ListNode(sum);
                item.next = null;
                if (isFirstNode) {
                    result = item;
                    pointer = item;
                    isFirstNode = false;
                } else {
                    pointer.next = item;
                    pointer = item;
                }
            }
            l1 = l1.next;
            l2 = l2.next;
        } while (l1 != null && l2 != null);
        if (l1 != null) {
            // l2 == null
            if (carryFlag == 1) {
                l1.val = l1.val + 1;
            }
            pointer.next = l1;
        } else if (l2 != null) {
            if (carryFlag == 1) {
                l2.val = l2.val + 1;
            }
            pointer.next = l2;
        } else if (carryFlag == 1) {
            ListNode item = new ListNode(carryFlag);
            item.next = null;
            pointer.next = item;
        }
        ListNode current = result;
        carryFlag = 0;
        ListNode last = null;
        do {
            int sum = current.val + carryFlag;
            if (sum > 9) {
                current.val = sum - 10;
                carryFlag = 1;
            } else {
                current.val = sum;
                carryFlag = 0;
            }
            if (current.next == null) {
                last = current;
            }
            current = current.next;
        } while (current != null);
        if (carryFlag == 1) {
            ListNode item = new ListNode(carryFlag);
            item.next = null;
            last.next = item;
        }
        return result;
    }

    public ListNode addTwoNumbers1(ListNode l1, ListNode l2) {
        /*
          这个dummy Header设置的非常好，类似于哨兵。
         */
        ListNode dummyNode = new ListNode(0);
        ListNode p = l1, q = l2, current = dummyNode;
        int carry = 0;
        /* 这个地方设置的条件很好，只有两个链表同时为0时，循环才能结束，
           只有一个链表为空时，while循环继续进行。
         */
        while (p != null || q != null) {
            /*如果一个链表的为空，另一个链表不为空，则继续进行操作，为空的列表加0就可以了。*/
            int x = (p != null) ? p.val : 0;
            int y = (q != null) ? q.val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            current.next = new ListNode(sum % 10);
            current = current.next;
            if (p != null) {
                p = p.next;
            }
            if (q != null) {
                q = q.next;
            }
        }
        /* 查看最后一位是否有进位，如果有的话，直接补一个节点。*/
        if (carry > 0) {
            current.next = new ListNode(carry);
        }
        return dummyNode.next;
    }

    public ListNode addTwoNumbersQuick(ListNode l1, ListNode l2) {
        ListNode rs = null;
        ListNode last = null;
        ListNode cur = null;
        int val = 0;
        while (null != l1 || null != l2) {
            if (null != l1) {
                val += l1.val;
                l1 = l1.next;
            }
            if (null != l2) {
                val += l2.val;
                l2 = l2.next;
            }
            cur = new ListNode(val % 10);
            val = val / 10;
            if (null == last) {
                rs = cur;
            } else {
                last.next = cur;
            }
            last = cur;
        }
        if (val > 0) {
            cur = new ListNode(val);
            last.next = cur;
        }
        return rs;
    }

    public static void main(String[] arguments) {
        // 2 -> 4 -> 3
        // 5 -> 6 -> 4
        // 7 -> 0 -> 8
        ListNode first = new ListNode(2);
        ListNode sec = new ListNode(4);
        ListNode third = new ListNode(3);
        first.next = sec;
        sec.next = third;
        third.next = null;

        ListNode four = new ListNode(5);
        ListNode five = new ListNode(6);
        ListNode six = new ListNode(4);
        four.next = five;
        five.next = six;
        six.next = null;

        ListNode l1 = new ListNode(9);
        ListNode l12 = new ListNode(9);
        l1.next = l12;
        l12.next = null;
        ListNode l2 = new ListNode(1);
        l2.next = null;

        Solution solution = new Solution();
        ListNode result = solution.addTwoNumbers1(l1, l2);
        do {
            System.out.println(result.val);
            result = result.next;
        } while (result != null);
    }
}
