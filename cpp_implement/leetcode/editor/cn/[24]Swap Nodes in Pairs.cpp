// Given a linked list, swap every two adjacent nodes and return its head. You
// must solve the problem without modifying the values in the list's nodes
// (i.e., only nodes themselves may be changed.)
//
//
//  Example 1:
//
//
//  Input: head = [1,2,3,4]
//
//
//  Output: [2,1,4,3]
//
//  Explanation:
//
//
//
//  Example 2:
//
//
//  Input: head = []
//
//
//  Output: []
//
//  Example 3:
//
//
//  Input: head = [1]
//
//
//  Output: [1]
//
//  Example 4:
//
//
//  Input: head = [1,2,3]
//
//
//  Output: [2,1,3]
//
//
//  Constraints:
//
//
//  The number of nodes in the list is in the range [0, 100].
//  0 <= Node.val <= 100
//
//
//  Related Topics 递归 链表 👍 2397 👎 0
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
    ListNode* swapPairs(ListNode* head) {
        // 做这个题目我犯错的地方是 pre 节点的初始化, 这个初始化是不能放在 while
        // 循环里面的,pre 和 p 节点先经过初始化, 然后在 while 循环里面再进行更新
        ListNode* guard_node = new ListNode(-1);
        guard_node->next     = head;
        ListNode* pre        = guard_node;
        ListNode* p          = head;
        while (p != nullptr && p->next != nullptr) {
            ListNode* q = p->next;
            SwapListNode(pre, p, q);
            pre = p;
            p   = p->next;
        }
        return guard_node->next;
    }

   private:
    void SwapListNode(ListNode* pre, ListNode* p, ListNode* q) {
        if (p == nullptr || q == nullptr) {
            return;
        }
        pre->next = q;
        p->next   = q->next;
        q->next   = p;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
