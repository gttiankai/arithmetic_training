// Given the head of a linked list, return the list after sorting it in
// ascending order.
//
//
//  Example 1:
//
//
// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
//
//
//  Example 2:
//
//
// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
//
//
//  Example 3:
//
//
// Input: head = []
// Output: []
//
//
//
//  Constraints:
//
//
//  The number of nodes in the list is in the range [0, 5 * 10⁴].
//  -10⁵ <= Node.val <= 10⁵
//
//
//
//  Follow up: Can you sort the linked list in O(n logn) time and O(1) memory
//  (i.
// e. constant space)?
//
//  Related Topics 链表 双指针 分治 排序 归并排序 👍 2536 👎 0

#include <iostream>

#include "list_node.h"
// leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    // 归并排序,自顶往下
    // 时间复杂度: O(N * logN)
    // 空间复杂度: O(logN), 空间复杂取决于递归调用栈的长度,
    ListNode* sortListUpToDown(ListNode* head) {
        return sortList(head, nullptr);
    }

   private:
    // sorList 排序的 list 是前闭后开的
    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (head == nullptr) {
            return head;
        }
        // 下面的代码将 list 进行分割
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        return merget(sortList(head, mid), sortList(mid, tail));
    }
    ListNode* merget(ListNode* head1, ListNode* head2) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* cur        = dummy_head;
        ListNode* p1         = head1;
        ListNode* p2         = head2;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val <= p2->val) {
                cur->next = p1;
                p1        = p1->next;
            } else {
                cur->next = p2;
                p2        = p2->next;
            }
            cur = cur->next;
        }
        if (p1 != nullptr) {
            cur->next = p1;
        } else if (p2 != nullptr) {
            cur->next = p2;
        }
        return dummy_head->next;
    }

   public:
    // 自底往上
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int size         = getSize(head);
        auto dummy_head  = new ListNode(0);
        dummy_head->next = head;
        for (int sub_len = 1; sub_len <= size; sub_len *= 2) {
            ListNode* prev = dummy_head;
            ListNode* cur  = dummy_head->next;
            while (cur != nullptr) {
                ListNode* head1 = cur;
                for (int i = 1; i < sub_len && cur->next != nullptr; i++) {
                    cur = cur->next;
                }
                ListNode* head2 = cur->next;
                cur->next       = nullptr;
                cur             = head2;
                for (int i = 1;
                     i < sub_len && cur != nullptr && cur->next != nullptr;
                     i++) {
                    cur = cur->next;
                }
                ListNode* next = nullptr;
                if (cur != nullptr) {
                    next      = cur->next;
                    cur->next = nullptr;
                }
                ListNode* merged = merget(head1, head2);
                prev->next       = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                cur = next;
            }
        }

        return dummy_head->next;
    }

   private:
    int getSize(ListNode* head) {
        int size = 0;
        while (head != nullptr) {
            size++;
            head = head->next;
        }
        return size;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::string> test_case = {"[4,2,1,3]", "[-1,0,3,4,5]"};

    for (auto case_ : test_case) {
        ListNode* head = StringToListNode(case_);
        head           = solution.sortList(head);
        std::cout << ListNodeToString(head) << std::endl;
    }
}