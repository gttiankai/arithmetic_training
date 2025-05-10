// Given the head of a sorted linked list, delete all nodes that have duplicate
// numbers, leaving only distinct numbers from the original list. Return the
// linked list sorted as well.
//
//
//  Example 1:
//
//
// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
//
//
//  Example 2:
//
//
// Input: head = [1,1,1,2,3]
// Output: [2,3]
//
//
//
//  Constraints:
//
//
//  The number of nodes in the list is in the range [0, 300].
//  -100 <= Node.val <= 100
//  The list is guaranteed to be sorted in ascending order.
//
//
//  Related Topics 链表 双指针 👍 1367 👎 0
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
    ListNode* deleteDuplicatesComplex(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* guard = new ListNode(101);
        guard->next     = head;
        ListNode* pre   = guard;
        ListNode* p     = head;
        ListNode* q     = head->next;
        while (q != nullptr) {
            if (p->val == q->val) {
                while (q != nullptr && p->val == q->val) {
                    q = q->next;
                }
                pre->next = q;
                if (q == nullptr) {
                    break;
                }
                p = q;
                q = q->next;
            } else {
                pre = pre->next;
                p   = q;
                q   = q->next;
            }
        }
        return guard->next;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur   = dummy;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                // 下面 for 循环式需要琢磨的地方
                while (cur->next != nullptr && x == cur->next->val) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    ListNode* head = StringToListNode("[1, 1]");
    Solution solution;
    solution.deleteDuplicates(head);
}
