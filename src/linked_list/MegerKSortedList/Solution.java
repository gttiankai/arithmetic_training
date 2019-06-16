/**
 * Merge k sorted linked lists and return it as one sorted list.
 * <p>
 * Analyze and describe its complexity.
 * <p>
 * Example:
 * <p>
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * <p>
 * <p>
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) { val = x; }
 * }
 * <p>
 * 思考: 这个题目有两种做法:
 * 1. 可以使用之前的每两个链表进行合并,也就是将 K 个链表两个两个进行合并
 * 2. 一次性合并所有的链表,这个应该如何实现, 参考了网上的办法,使用堆排序进行处理.
 * 其实这里也可以使用多种排序算法
 * <p>
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) { val = x; }
 * }
 * <p>
 * 思考: 这个题目有两种做法:
 * 1. 可以使用之前的每两个链表进行合并,也就是将 K 个链表两个两个进行合并
 * 2. 一次性合并所有的链表,这个应该如何实现, 参考了网上的办法,使用堆排序进行处理.
 * 其实这里也可以使用多种排序算法
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

/**
 * 思考: 这个题目有两种做法:
 * 1. 可以使用之前的每两个链表进行合并,也就是将 K 个链表两个两个进行合并
 * 2. 一次性合并所有的链表,这个应该如何实现, 参考了网上的办法,使用堆排序进行处理.
 *    其实这里也可以使用多种排序算法
 *
 * */

package linked_list.MegerKSortedList;

class Solution {
    //
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (null == l1 && null == l2) {
            return null;
        }
        ListNode tmp = new ListNode(0);
        ListNode header = tmp;

        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                tmp.next = l1;
                tmp = tmp.next;
                l1 = l1.next;
            } else {
                tmp.next = l2;
                tmp = tmp.next;
                l2 = l2.next;
            }
        }
        if (l1 == null && l2 != null) {
            tmp.next = l2;
        }
        if (l1 != null && l2 == null) {
            tmp.next = l1;
        }
        return header.next;
    }

    public ListNode mergeKLists(ListNode[] lists) {
        if (null == lists || 0 == lists.length) {
            return null;
        }
        int listNumber = lists.length;
        ListNode guard = null;
        for (int i = 0; i < listNumber; ++i) {
            ListNode pointer = lists[i];
            guard = mergeTwoLists(guard, pointer);
        }
        return guard;
    }

    /**
     *  我写的这个方法应该可以了,但是由于速度太慢了,所以直接 time limit exceeded
     * （1）取k个元素建立最小堆，这k个元素分别是k个链表的第一个元素。建堆的时间复杂度O(k)。
     *
     * （2）堆顶元素就是k个链表中最小的那个元素，取出它。时间复杂度O(1)。
     *
     * （3）若堆顶元素所在链表不为空，则取下一个元素放到堆顶位置，这可能破坏了最小堆性质，所以进行堆调整。堆调整时间复杂度O(lgk)。
     *     若为空，则此子链表已经被合并完毕，则删除最小堆的堆顶元素，此时最小堆的heapSize减小了1 。删除指定元素时间复杂度O(lgk)。
     *
     * （4）重复步骤（2）~（3）n-k次。总的时间复杂度是O(k)+O(nlgk)即O(nlgk)。
     **/
    public static ListNode mergeKListsOtherWay(ListNode[] lists) {
        if (null == lists || 0 == lists.length ) {
            return null;
        }
        // init array
        int length = lists.length;
        int heapSize = 0;
        int i = 0;
        while (i < length) {
            if (lists[i] != null) {
                heapSize++;
            }
            i++;
        }
        // 更新的后的 heap size
        if (heapSize < 1) {
            return null;
        }
        ListNode[] array = new ListNode[heapSize];
        int count = 0;
        while (count < heapSize) {
            if (lists[count] != null) {
                array[count] = lists[count];
                count++;
            }
        }
        heapSort(array, heapSize);
        ListNode guard = new ListNode(0);
        ListNode pointer = guard;

        while (heapSize > 0) {
            // 取出栈顶元素
            pointer.next = array[0];
            pointer = pointer.next;

            // 取下一个元素
            // 当栈顶元素的下一个节点不为空时,直接取下一个元素
            // 当栈顶元素的下一个节点为空时,删除当前堆
            if (array[0].next != null) {
                array[0] = array[0].next;
                heapSort(array, heapSize);
            } else {
                // 栈顶元素的下一个值为空,这个链表就不需要了
                array[0] = array[heapSize-1];
                array[heapSize-1] = null;
                heapSize = heapSize -1;
                heapSort(array, heapSize);
            }

        }
        return guard.next;
    }

    private static void heapSort(ListNode[] array, int heapSize) {
        if (array == null || array.length == 0 || heapSize == 0) {
            return;
        }
        int length = heapSize;
        int beginIndex = length / 2 - 1;
        // 从底到上, 进行堆排序
        for (int i = beginIndex; i >= 0; i--) {
            heapity(array, length, i);
        }

    }

    // 进行堆的调整
    private static void heapity(ListNode[] array, int heapSize, int rootNumber) {
        int minNumber = rootNumber;
        int left = 2 * rootNumber + 1;
        int right = 2 * rootNumber + 2;
        if (left < heapSize && array[left].val < array[minNumber].val) {
            minNumber = left;
        }
        if (right < heapSize && array[right].val < array[minNumber].val) {
            minNumber = right;
        }

        if (rootNumber != minNumber) {
            ListNode tmp = array[rootNumber];
            array[rootNumber] = array[minNumber];
            array[minNumber] = tmp;
        }
    }
    public static void main(String[] arguments) {
        ListNode n1 = new ListNode(2);
        ListNode n4 = new ListNode(4);
        ListNode n5 = new ListNode(5);
        n1.next = n4;
        n4.next = n5;
        n5.next = null;

        ListNode n11 = new ListNode(4);
        ListNode n3 = new ListNode(3);
        ListNode n44 = new ListNode(4);
        n11.next = n3;
        n3.next = n44;
        n44.next = null;

        ListNode n2 = new ListNode(1);
        ListNode n6 = new ListNode(6);
        n2.next = n6;
        n6.next = null;

//        ListNode[] array = new ListNode[3];
//        array[0] = n1;
//        array[1] = n11;
//        array[2] = n2;

//        mergeKListsOtherWay(array);
        ListNode[] array = new ListNode[2];
        array[0] = null;
        array[1] = new ListNode(1);
        mergeKListsOtherWay(array);

        //System.out.printf("the values: " + array);

    }
}
